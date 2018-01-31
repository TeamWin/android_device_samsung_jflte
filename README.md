## TWRP device tree for Samsung Galaxy S4 (GT-I9505/G, SGH-M919)
## jflte, jfltetmo, jfltexx, jgedlte

Add to `.repo/local_manifests/jfltexx.xml`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
  <project name="ripee/twrp_android_device_samsung_jfltexx" path="device/samsung/jfltexx" remote="github" revision="android-7.1" />
</manifest>
```

Then run `repo sync` to check it out.

To build:

```sh
. build/envsetup.sh
lunch omni_jfltexx-eng
mka recoveryimage
```

Kernel source: https://github.com/LineageOS/android_kernel_samsung_jf/tree/cm-14.1
