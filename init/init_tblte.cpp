/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include <android-base/logging.h>
#include <android-base/properties.h>
#include "log.h"
#include "util.h"

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include "property_service.h"
#include <sys/system_properties.h>

using android::base::GetProperty;

void init_variant_properties() {

    std::string platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
         return;

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("N915A") == 0) {
        android::init::property_set("ro.product.model", "SM-N915A");
        android::init::property_set("ro.product.device", "tblteatt");
    } else if (bootloader.find("N915F") == 0) {
        android::init::property_set("ro.product.model", "SM-N915F");
        android::init::property_set("ro.product.device", "tblte");
    } else if (bootloader.find("N915FY") == 0) {
        android::init::property_set("ro.product.model", "SM-N915FY");
        android::init::property_set("ro.product.device", "tblte");    
    } else if (bootloader.find("N915G") == 0) {
        android::init::property_set("ro.product.model", "SM-N915G");
        android::init::property_set("ro.product.device", "tbltedt");
    } else if (bootloader.find("N915R4") == 0) {
        android::init::property_set("ro.product.model", "SM-N915R4");
        android::init::property_set("ro.product.device", "tblteusc");
    } else if (bootloader.find("N915P") == 0) {
        android::init::property_set("ro.product.model", "SM-N915P");
        android::init::property_set("ro.product.device", "tbltespr");
    } else if (bootloader.find("N915T") == 0) {
        android::init::property_set("ro.product.model", "SM-N915T");
        android::init::property_set("ro.product.device", "tbltetmo");
    } else if (bootloader.find("N915V") == 0) {
        android::init::property_set("ro.product.model", "SM-N915V");
        android::init::property_set("ro.product.device", "tbltevzw");
    } else if (bootloader.find("N915W8") == 0) {
        android::init::property_set("ro.product.model", "SM-N915W8");
        android::init::property_set("ro.product.device", "tbltecan");
    } else {
        android::init::property_set("ro.product.model", "ro.product.model");
        android::init::property_set("ro.product.device", "ro.product.device");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(INFO) << "Found bootloader id " << bootloader << " setting build properties for " << device << " device" << std::endl;
}

// Android 8.1 has to use namespace android::init
namespace android {
namespace init {

void vendor_load_properties() {
    init_variant_properties();
    }
}  // namespace init
} // namespace android
