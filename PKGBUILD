# Maintainer: Tom Meyers tom@odex.be
pkgname=installer-gui
pkgver=r22.9273531
pkgrel=1
pkgdesc="GUI for installing TOS"
arch=(any)
url="https://github.com/ODEX-TOS/installer-gui"
_reponame="installer-gui"
license=('GPL')

source=(
"git+https://github.com/ODEX-TOS/installer-gui.git"
"https://github.com/ODEX-TOS/installer-gui/releases/download/v0.2.0/installer")
md5sums=('SKIP' 'SKIP')
depends=('installer-backend' 'qt5-base' 'qt5-declarative' 'qt5-quickcontrols' 'qt5-quickcontrols2' 'qt5-graphicaleffects')
makedepends=('git')

pkgver() {
  cd "$srcdir/$_reponame"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}


build() {
    return 0;
}

package() {
        install -Dm755 installer "$pkgdir"/usr/bin/tos-gui-installer
        cd "$srcdir/$_reponame"
        mkdir -p "$pkgdir"/usr/share/tos-gui-installer
        for file in config/* ; do
            install -Dm755 "$file" "$pkgdir"/usr/share/tos-gui-installer/"$file"
        done
}
