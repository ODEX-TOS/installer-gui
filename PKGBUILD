# Maintainer: Tom Meyers tom@odex.be
pkgname=installer-gui
pkgver=r9.3c80a94
pkgrel=1
pkgdesc="GUI for installing TOS"
arch=(any)
url="https://github.com/ODEX-TOS/installer-gui"
_reponame="installer-gui"
license=('GPL')

source=(
"git+https://github.com/ODEX-TOS/installer-gui.git"
"https://github.com/ODEX-TOS/installer-gui/releases/download/v0.0.1/installer")
md5sums=('SKIP' 'SKIP')
depends=('installer-backend')
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
        install -Dm755 -d config "$pkgdir"/usr/share/tos-gui-installer/
}
