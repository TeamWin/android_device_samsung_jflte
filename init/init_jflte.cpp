/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
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

#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"
#include "util.h"

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader, NULL);

    if (strstr(bootloader, "M919")) {
        property_override("ro.product.model", "SGH-M919");
        property_override("ro.product.device", "jfltetmo");
    } else if (strstr(bootloader, "I9505G")) {
        property_override("ro.product.model", "GT-I9505G");
        property_override("ro.product.device", "jgedlte");
    } else if (strstr(bootloader, "I9505")) {
        property_override("ro.product.model", "GT-I9505");
        property_override("ro.product.device", "jflte");
    } else if (strstr(bootloader, "R970C")) {
        property_override("ro.product.model", "SCH-R970C");
        property_override("ro.product.device", "jfltecri");
    } else if (strstr(bootloader, "R970X")) {
        property_override("ro.product.model", "SCH-R970X");
        property_override("ro.product.device", "jfltecsp");
    } else if (strstr(bootloader, "R970")) {
        property_override("ro.product.model", "SCH-R970");
        property_override("ro.product.device", "jflteusc");
    } else if (strstr(bootloader, "L720")) {
        property_override("ro.product.model", "SPH-L720");
        property_override("ro.product.device", "jfltespr");
    } else if (strstr(bootloader, "I337M")) {
        property_override("ro.product.model", "SGH-I337M");
        property_override("ro.product.device", "jfltecan");
    } else if (strstr(bootloader, "I337")) {
        property_override("ro.product.model", "SGH-I337");
        property_override("ro.product.device", "jflteatt");
    } else if (strstr(bootloader, "I545L")) {
        property_override("ro.product.model", "SCH-I545L");
        property_override("ro.product.device", "jfltelra");
    } else if (strstr(bootloader, "I545")) {
        property_override("ro.product.model", "SCH-I545");
        property_override("ro.product.device", "jfltevzw");
    }

    property_get("ro.product.device", device, NULL);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}