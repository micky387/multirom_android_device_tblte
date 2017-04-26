#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    "/sys/class/graphics/fb0",
    "/sys/class/graphics/fb1",
    "/sys/class/graphics/fb2",
    "/sys/devices/virtual/graphics/fb0",
    "/sys/devices/virtual/graphics/fb1",
    "/sys/devices/virtual/graphics/fb2",
    
    // Storage devices
    "/sys/dev/block*",
    "/sys/block/mmcblk0",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    // EMMC stuff
	"/sys/block/mmcblk0",
    "/sys/devices/msm_sdcc.1",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc1",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc1/mmc1:0001",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc1/mmc1:0001/block/mmcblk0",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p17", // boot
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p25", // cache
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p2", // modem
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p22", // persist
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p24", // system
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p27", // userdata
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1", // firmware
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p26", // hidden
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p20", // misc
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p13", // efs
	"/sys/bus/mmc",
	"/sys/bus/mmc/drivers/mmcblk",
	"/sys/module/mmcblk",
	"/sys/module/mmc_core",
	
	// MicroSD card
	"/sys/block/mmcblk1",
	"/dev/block/mmcblk1p1"
    "/devices/msm_sdcc.2/mmc_host*",

    "/sys/devices/gpio_keys.82/input*",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/f9966000.i2c/i2c-1/1-0049/input*",

    // for adb
    "/sys/devices/virtual/tty/ptmx",
    "/sys/devices/virtual/misc/android_adb",
    "/sys/devices/virtual/android_usb/android0/f_adb",
    "/sys/bus/usb",

    // USB drive is in here
    "/sys/devices/platform/xhci-hcd*",

    // Encryption
    //"/sys/devices/virtual/misc/device-mapper",
    //"/sys/devices/virtual/misc/ion",
    //"/sys/devices/virtual/qseecom/qseecom",

    NULL
};
