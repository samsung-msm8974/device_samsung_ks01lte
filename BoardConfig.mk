# Copyright (C) 2014-2016 The CyanogenMod Project
# Copyright (C) 2017-2021 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common ks01lte
include device/samsung/msm8974-common/BoardConfigCommon.mk

DEVICE_PATH := device/samsung/ks01lte

TARGET_OTA_ASSERT_DEVICE := ks01lte,ks01ltexx,GT-I9506,ks01lteskt,ks01ltektt,ks01ltelgt

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_PATH)/bluetooth
BOARD_CUSTOM_BT_CONFIG := $(DEVICE_PATH)/bluetooth/vnd_ks01ltexx.txt

# Build Fingerprint
BUILD_FINGERPRINT := samsung/ks01ltexx/ks01lte:5.0.1/LRX22C/I9506XXUDRB1:user/release-keys

# Kernel
TARGET_KERNEL_CONFIG := lineage_ks01lte_defconfig

# Init
TARGET_INIT_VENDOR_LIB := libinit_ks01lte

# Partition
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2390753280	  # Dont change it
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12528352256

# NFC
include $(COMMON_PATH)/nfc/bcm2079x/board.mk

# Radio/RIL
include $(COMMON_PATH)/radio/single/board.mk

# inherit from the proprietary version
include vendor/samsung/ks01lte/BoardConfigVendor.mk
