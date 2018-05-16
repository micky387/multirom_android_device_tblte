ifneq ($(filter tblte,$(TARGET_DEVICE)),)
    include $(all-subdir-makefiles)
endif
