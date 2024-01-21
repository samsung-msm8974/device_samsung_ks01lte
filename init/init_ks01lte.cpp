/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

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

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "init_msm8974.h"

using android::base::GetProperty;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("I9506") == 0) {
        /* ks01lte */
        property_override("ro.build.description", "samsung/ks01ltexx/ks01lte:5.0.1/LRX22C/I9506XXUDRB1:user/release-keys");
        property_override("persist.radio.add_power_save", "0");
        set_ro_product_prop("device", "ks01lte");
        set_ro_product_prop("build.fingerprint", "ks01ltexx-user 5.0.1 LRX22C I9506XXUDRB1 release-keys");
        set_ro_product_prop("model", "GT-I9506");
        set_ro_product_prop("name", "ks01lte");
        gsm_properties("9", "gsm");
    } else if (bootloader.find("E330S") == 0) {
        /* ks01lteskt */
        property_override("ro.build.description", "ks01lteskt-user 5.0.1 LRX22C E300SKSUDPI2 release-keys");
        property_override("persist.radio.add_power_save", "0");
        set_ro_product_prop("device", "ks01lteskt");
        set_ro_product_prop("build.fingerprint", "samsung/ks01lteskt/ks01lte:5.0.1/LRX22C/E330SKSUDPI2:user/release-keys");
        set_ro_product_prop("model", "SHV-E330S");
        set_ro_product_prop("name", "ks01lteskt");
        gsm_properties("9", "gsm");    
    } else if (bootloader.find("E330K") == 0) {
        /* ks01ltektt */
        property_override("ro.build.description", "ks01ltektt-user 5.0.1 LRX22C E330KKKUDPH1 release-keys");
        property_override("persist.radio.add_power_save", "0");
        set_ro_product_prop("device", "ks01ltektt");
        set_ro_product_prop("build.fingerprint", "samsung/ks01ltektt/ks01lte:5.0.1/LRX22C/E330KKKUDPH1:user/release-keys");
        set_ro_product_prop("model", "SHV-E330K");
        set_ro_product_prop("name", "ks01ltektt");
        gsm_properties("9", "gsm");   
    } else if (bootloader.find("E330L") == 0) {
        /* ks01ltelgt */
        property_override("ro.build.description", "ks01ltelgt-user 5.0.1 LRX22C E330LKLUDPH4 release-keys");
        property_override("persist.radio.add_power_save", "0");
        set_ro_product_prop("device", "ks01ltelgt");
        set_ro_product_prop("build.fingerprint", "samsung/ks01ltelgt/ks01lte:5.0.1/LRX22C/E330LKLUDPH4:user/release-keys");
        set_ro_product_prop("model", "SHV-E330L");
        set_ro_product_prop("name", "ks01ltelgt");
        gsm_properties("9", "gsm");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
