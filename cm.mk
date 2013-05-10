$(call inherit-product, device/samsung/jfltexx/full_jfltexx.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/gsm.mk)

# Enhanced NFC
$(call inherit-product, vendor/cm/config/nfc_enhanced.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=jfltexx TARGET_DEVICE=jfltexx BUILD_FINGERPRINT="samsung/jfltexx/jfltexx:4.2.2/JDQ39/M919UVUAMDB:user/release-keys" PRIVATE_BUILD_DESC="jfltexx-user 4.2.2 JDQ39 M919UVUAMDB release-keys"

PRODUCT_NAME := cm_jfltexx
PRODUCT_DEVICE := jfltexx

