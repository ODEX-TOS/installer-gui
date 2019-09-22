
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![GPL License][license-shield]][license-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/ODEX-TOS/installer-gui">
    <img src="https://tos.pbfp.xyz/images/logo.svg" alt="Logo" width="150" height="200">
  </a>

  <h3 align="center">GUI installer</h3>

  <p align="center">
    Elegant and modern and customizable OS installer
    <br />
    <a href="https://github.com/ODEX-TOS/installer-gui"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/ODEX-TOS/installer-gui">View Demo</a>
    ·
    <a href="https://github.com/ODEX-TOS/installer-gui/issues">Report Bug</a>
    ·
    <a href="https://github.com/ODEX-TOS/installer-gui/issues">Request Feature</a>
  </p>
</p>

> This project is currently no longer maintained. Our gui installer is migrated to calamares. You can still install `TOS` using calamares or the installer-curses.


<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)



<!-- ABOUT THE PROJECT -->
## About The Project

This project is a interface/frontend for the tos-installer-backend
It generates a yaml file that is capable of installing TOS. You can easily customize this installer to generate yaml files for other operating systems by editing the config directory.
<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites
On arch based distro's you can simply run makepkg to build the software.

Here is a list of dependencies

* LibX11 (You have this if you are using the X server)
* tos-installer-backend (look at ODEX-TOS github and/or the PKGBUILD for more information)
* python3
* PyYaml

### Installation
 
1. Clone the installer-gui
```sh
git clone https://github.com/ODEX-TOS/installer-gui.git
```
2. Make sure os-install is in your path
```sh
command -v os-install
```
If it isn't simply clone the backend installer
```sh
git clone https://github.com/ODEX-TOS/tos-installer-backend.git
cd tos-installer-backend
python3 setup.py install
sudo cp os-install /usr/bin/os-install # or any other directory in your path
```

3. verify again if os-install works
4. run the gui (as a root if you want to install an os)

> Make sure you don't by accident install TOS over your environment as this can break your current system. Always make backups in case data is lost


<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://tos.pbfp.xyz/blog)_



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/ODEX-TOS/installer-gui/issues) for a list of proposed features (and known issues).



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the GPL License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

F0xedb - tom@odex.be

Project Link: [https://github.com/ODEX-TOS/installer-gui](https://github.com/ODEX-TOS/installer-gui)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* [ODEX-TOS](https://github.com/ODEX-TOS/installer-gui)





<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/ODEX-TOS/installer-gui.svg?style=flat-square
[contributors-url]: https://github.com/ODEX-TOS/installer-gui/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/ODEX-TOS/installer-gui.svg?style=flat-square
[forks-url]: https://github.com/ODEX-TOS/installer-gui/network/members
[stars-shield]: https://img.shields.io/github/stars/ODEX-TOS/installer-gui.svg?style=flat-square
[stars-url]: https://github.com/ODEX-TOS/installer-gui/stargazers
[issues-shield]: https://img.shields.io/github/issues/ODEX-TOS/installer-gui.svg?style=flat-square
[issues-url]: https://github.com/ODEX-TOS/installer-gui/issues
[license-shield]: https://img.shields.io/github/license/ODEX-TOS/installer-gui.svg?style=flat-square
[license-url]: https://github.com/ODEX-TOS/installer-gui/blob/master/LICENSE.txt
[product-screenshot]: https://tos.pbfp.xyz/images/logo.svg
