## TWRP device tree for Samsung Galaxy S4 (Qualcomm)
## jflteatt, jfltecan, jfltecri, jfltecsp, jfltelra, jfltespr, jfltetmo, jflteusc, jfltevzw, jfltexx, jgedlte

Add to `.repo/local_manifests/jflte.xml`:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<manifest>
  <project name="TeamWin/android_device_samsung_jflte" path="device/samsung/jflte" remote="github" revision="android-7.1" />
</manifest>
```

Then run `repo sync` to check it out.

To build:

```sh
. build/envsetup.sh
lunch omni_jflte-eng
mka recoveryimage
```

Kernel source: https://github.com/LineageOS/android_kernel_samsung_jf/tree/cm-14.1