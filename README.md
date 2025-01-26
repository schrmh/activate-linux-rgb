# activate-linux-rgb
Won't maintain, just a quick thing added by Claude w/o cleaning up stuff it changed unnecessarily.


https://github.com/user-attachments/assets/48d73663-c6b8-4273-9b0a-73d6739a87f3



[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

The "Activate Windows" watermark ported to Linux with cairo in C

"Science isn't about WHY. It's about WHY NOT. Why is so much of our science dangerous? Why not marry safe science if you love it so much. In fact, why not invent a special safety door that won't hit you on the butt on the way out, because you are fired." — Cave Johnson (Portal 2)

> Read [ARGS.md](ARGS.md) for information about command line arguments.

## Building
Note that the executable's name depends on the target platform.
You can use `make install` to install and `make uninstall` to remove it.

### Xmake
I've been experimenting with using [Xmake](https://xmake.io/#/) for building instead of make, you can test this by installing it and running
```console
xmake
```
Please leave feedback to improve this if you want

### *nix:
```console
make
```

### Windows (using [MSYS2](https://msys2.org)):
Replace `gcc` with `clang`, if you want. But then don't forget to start proper shortcut `MSYS2 CLANG64`.
```console
pacman -S --noconfirm git make pkgconf pactoys
pacboy -S --noconfirm gcc:p
git clone https://github.com/MrGlockenspiel/activate-linux
cd activate-linux
export backends=gdi
make
```

## Linux

### Dependencies
This project depends on:
- [`libcairo2-dev`](https://cairographics.org)
- [`libxi-dev`](https://gitlab.freedesktop.org/xorg/lib/libxi)
- [`libx11-dev`](https://gitlab.freedesktop.org/xorg/lib/libx11)
- `x11proto-core-dev`
- [`x11proto-dev`](https://gitlab.freedesktop.org/xorg/proto/x11proto)
- [`libxt-dev`](https://gitlab.freedesktop.org/xorg/lib/libxt)
- [`libxext-dev`](https://gitlab.freedesktop.org/xorg/lib/libxext)
- [`libxfixes-dev`](https://gitlab.freedesktop.org/xorg/lib/libxfixes)
- [`libxinerama-dev`](https://gitlab.freedesktop.org/xorg/lib/libxinerama)
- [`libxrandr-dev`](https://gitlab.freedesktop.org/xorg/lib/libxrandr)
- [`libwayland-dev`](https://gitlab.freedesktop.org/wayland/wayland)
- [`wayland-protocols`](https://gitlab.freedesktop.org/wayland/wayland-protocols)

Optional dependencies:
- [`libconfig-dev`](https://hyperrealm.github.io/libconfig)

Those packages may be installed (in Debian-based distros) like this:
```console
sudo apt install libconfig-dev libcairo2-dev libxi-dev libx11-dev x11proto-core-dev x11proto-dev \
libxt-dev libxext-dev libxfixes-dev libxinerama-dev libxrandr-dev libwayland-dev wayland-protocols
```


### Installing

#### Ubuntu
@eddelbuettel runs a PPA with activate linux in it, so it can be installed with:
```console
sudo add-apt-repository ppa:edd/misc
sudo apt update
sudo apt install activate-linux
```

#### Arch Linux
This project is in the AUR under [activate-linux-git](https://aur.archlinux.org/packages/activate-linux-git).

Install/uninstall it using your favorite AUR helper.

#### Nix (NixOS)
This repository is a flake. Run it using `nix run "github:MrGlockenspiel/activate-linux"`.

#### Gentoo
@Plexvola maintains an ebuild for activate-linux and can be installed with the following
```console
eselect repository enable vaacus
emerge --sync vaacus
emerge -av activate-linux
```

#### openSUSE / SLE
The package is built for various releases on
[OBS](https://build.opensuse.org/package/show/home:tschmitz:activate-linux/activate-linux).

Installation instructions for your specific distribution are available here:
**[https://software.opensuse.org/download.html?project=home%3Atschmitz%3Aactivate-linux&package=activate-linux](https://software.opensuse.org/download.html?project=home%3Atschmitz%3Aactivate-linux&package=activate-linux)**

Here are the Tumbleweed instructions:
```console
zypper addrepo https://download.opensuse.org/repositories/home:tschmitz:activate-linux/openSUSE_Tumbleweed/home:tschmitz:activate-linux.repo
zypper refresh
zypper install activate-linux
```

#### Fedora
The package is built for various releases on
[OBS](https://build.opensuse.org/package/show/home:tschmitz:activate-linux/activate-linux).

Installation instructions for your specific distribution are available here:
**[https://software.opensuse.org/download.html?project=home%3Atschmitz%3Aactivate-linux&package=activate-linux](https://software.opensuse.org/download.html?project=home%3Atschmitz%3Aactivate-linux&package=activate-linux)**

Here are the Fedora Rawhide instructions:
```console
dnf config-manager --add-repo https://download.opensuse.org/repositories/home:tschmitz:activate-linux/Fedora_Rawhide/home:tschmitz:activate-linux.repo
dnf install activate-linux
```

## Windows

### Scoop

You can install it on the [Extras](https://github.com/ScoopInstaller/Extras) bucket:
```powershell
scoop bucket add extras # Ensure bucket is added first
scoop install activate-linux
```


## MacOS (Horrific)

### Dependencies

Use MacPorts to install the following, then build normally.

- `xorg-server`
- `cairo`
- `xorg-libXinerama`

Alternatively, you can use [this](https://github.com/Lakr233/ActivateMac) project instead because it actually works properly.

## Example:

![screenshot](screenshot.png)
