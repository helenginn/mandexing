# Mandexing
written by Helen Ginn

Mandexing allows you to manually index and modify parameters for X-ray beam/crystals and rotate them within the GUI, overlaid on an image file. The philosophy is that Mandexing will allow you to load standard image types (PNG, JPG, etc.) but at the expense of doing no pixel value-based analysis itself. This lends itself well to quick diffraction analysis on unusual file formats as it can work surprisingly well from screenshots alone. It only supports projections of reflections onto a flat detector.

Mandexing is also potentially a good teaching tool for understanding the effects of detector distance, wavelength, unit cell parameters, crystal rotation and so on.

Installation from scratch
=================

Installation works using the meson build system. Please install meson (including the ninja dependency) first.

```dnf install meson```

Clone the Mandexing repository and enter the directory.

```
git clone https://www.github.com/helenginn/mandexing.git
cd mandexing
```

Configure meson and compile with ninja.

```
meson builddir
cd builddir
ninja
```

Now you will have an executable in `{...}/mandexing/builddir/mandexing`, which you may run as so:

```
./mandexing
```

Contact me if you need.
