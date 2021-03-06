DEVICE_TREE := device/samsung/tblte

# Architecture
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_VARIANT := krait
TARGET_ARCH := arm
TARGET_KERNEL_ARCH := arm
TARGET_KERNEL_HEADER_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
ARCH_ARM_HAVE_TLS_REGISTER := true

# Flags
BOARD_GLOBAL_CFLAGS += -mfpu=neon -mfloat-abi=softfp
BOARD_GLOBAL_CPPFLAGS += -mfpu=neon -mfloat-abi=softfp

# Graphics
TARGET_USES_C2D_COMPOSITION := true
TARGET_USES_ION := true

# Kernel
BOARD_KERNEL_IMAGE_NAME := zImage
BOARD_CUSTOM_BOOTIMG_MK := $(DEVICE_TREE)/mkbootimg.mk
BOARD_KERNEL_CMDLINE :=  console=null androidboot.hardware=qcom user_debug=23 msm_rtb.filter=0x3b7 dwc3_msm.cpu_to_affin=1 androidboot.selinux=permissive
BOARD_KERNEL_BASE :=  0x00000000
BOARD_KERNEL_PAGESIZE := 4096
BOARD_KERNEL_SEPARATED_DT := true
BOARD_MKBOOTIMG_ARGS := --kernel_offset 0x00008000 --ramdisk_offset 0x02600000 --tags_offset 0x02400000 --board SYSMAGIC000RU

BOARD_FLASH_BLOCK_SIZE := 262144
BOARD_BOOTIMAGE_PARTITION_SIZE := 17825792 
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 199229440
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3774873600
BOARD_USERDATAIMAGE_PARTITION_SIZE := 27040657408
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := f2fs
BOARD_CACHEIMAGE_PARTITION_SIZE := 209715200

# Kernel Configs
TARGET_KERNEL_SOURCE := kernel/samsung/apq8084
TARGET_KERNEL_CONFIG := twrp_defconfig
TARGET_KERNEL_VARIANT_CONFIG := apq8084_sec_tblte_eur_defconfig
KERNEL_TOOLCHAIN        := $(ANDROID_BUILD_TOP)/prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin
KERNEL_TOOLCHAIN_PREFIX := arm-eabi-

TARGET_USE_CUSTOM_LUN_FILE_PATH := /sys/class/android_usb/android0/f_mass_storage/lun/file

# Platform
TARGET_BOARD_PLATFORM := apq8084
TARGET_BOARD_PLATFORM_GPU := qcom-adreno420
TARGET_BOOTLOADER_BOARD_NAME := APQ8084
TARGET_NO_BOOTLOADER := true

# Use this flag if the board has a ext4 partition larger than 2gb
BOARD_HAS_LARGE_FILESYSTEM := true
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_USE_F2FS := true
BOARD_HAS_DOWNLOAD_MODE := true
BOARD_SUPPRESS_SECURE_ERASE := true

BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_23x41.h\"

# Init properties from bootloader version, ex. model info
TARGET_UNIFIED_DEVICE := true
TARGET_INIT_VENDOR_LIB := libinit_tblte
TARGET_RECOVERY_DEVICE_MODULES += libinit_tblte tzdata
TARGET_LIBINIT_DEFINES_FILE := $(DEVICE_TREE)/init/init_tblte.cpp
TW_RECOVERY_ADDITIONAL_RELINK_FILES += $(OUT)/system/usr/share/zoneinfo/tzdata

#TWRP specific build flags
TW_DEVICE_VERSION := by micky387
TW_THEME := portrait_hdpi
TW_BRIGHTNESS_PATH := "/sys/class/leds/lcd-backlight/brightness"
TW_MAX_BRIGHTNESS := 255
TW_DEFAULT_BRIGHTNESS := 140
RECOVERY_SDCARD_ON_DATA := true
BOARD_HAS_NO_REAL_SDCARD := true
RECOVERY_GRAPHICS_USE_LINELENGTH := true
TW_INTERNAL_STORAGE_PATH := "/data/media/0"
TW_INTERNAL_STORAGE_MOUNT_POINT := "data"
TW_EXTERNAL_STORAGE_PATH := "/external_sd"
TW_EXTERNAL_STORAGE_MOUNT_POINT := "external_sd"
TW_NO_REBOOT_BOOTLOADER := true
TW_HAS_DOWNLOAD_MODE := true
TW_NO_EXFAT_FUSE := true
TARGET_RECOVERY_QCOM_RTC_FIX := true
TW_EXCLUDE_SUPERSU := true
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
TARGET_HW_DISK_ENCRYPTION := true
BOARD_SUPPRESS_SECURE_ERASE := true
BOARD_SUPPRESS_EMMC_WIPE := true
TW_INCLUDE_NTFS_3G := true
# exFAT drivers included in the kernel
TW_NO_EXFAT_FUSE := true

# Encryption support
TW_INCLUDE_CRYPTO := true
TW_CRYPTO_USE_SYSTEM_VOLD := qseecomd
TW_CRYPTO_SYSTEM_VOLD_DEBUG := true
TARGET_KEYMASTER_WAIT_FOR_QSEE := true

# MultiROM config. MultiROM also uses parts of TWRP config
TARGET_RECOVERY_IS_MULTIROM := true
MR_DEVICE_VARIANTS := tblteatt tbltecan tbltedt tbltetmo tblteusc tbltespr tbltevzw
MR_NO_KEXEC := enabled
MR_NO_KEXEC := true
MR_INPUT_TYPE := type_b
MR_INIT_DEVICES := $(DEVICE_TREE)/multirom/mr_init_devices.c
MR_CONTINUOUS_FB_UPDATE := true
MR_DPI := xxhdpi
MR_DPI_FONT := 435
MR_FSTAB := $(DEVICE_TREE)/multirom/mrom.fstab
MR_KEXEC_MEM_MIN := 0x20000000
MR_KEXEC_DTB := true
MR_DEVICE_HOOKS := $(DEVICE_TREE)/multirom/mr_hooks.c
MR_DEVICE_HOOKS_VER := 4
MR_UNIFIED_TABS := true
MR_USE_DEBUGFS_MOUNT := true
MR_PIXEL_FORMAT := "RGBX_8888"
MR_USE_QCOM_OVERLAY := true
MR_QCOM_OVERLAY_HEADER := $(DEVICE_TREE)/multirom/mr_qcom_overlay.h
MR_QCOM_OVERLAY_CUSTOM_PIXEL_FORMAT := MDP_RGBX_8888

# Versioning
include $(DEVICE_TREE)/multirom/MR_REC_VERSION.mk
BOARD_MKBOOTIMG_ARGS += --board mrom$(MR_REC_VERSION)
MR_REC_VERSION := $(shell date -u +%Y%m%d)-01

