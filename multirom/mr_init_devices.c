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

    "/sys/devices*",
    "/sys/bus*",
    
    // Storage devices
    "/sys/dev/block*",
    "/sys/block/mmcblk0",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    // EMMC stuff
	"/sys/block/mmcblk0",
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0*",
	"/dev/block/platform/msm_sdcc.1/by-name*",
	"/sys/bus/mmc/drivers/mmcblk",
	"/sys/module/mmcblk",
	"/sys/module/mmc_core",
	
	// MicroSD card
	"/sys/block/mmcblk1",
	"/dev/block/mmcblk1p1",
    "/devices/msm_sdcc.2/mmc_host*",

    // USB drive is in here
    "/sys/devices/platform/xhci-hcd*",

    NULL
};
