# PDNS Sysrepo Configurator

## How to set up a working development environment
This project requires sysrepo 1.2.x and its C++ bindings, which in turn require the libyang C++ bindings.

### Dependencies
This project uses C++11 and requires the following libraries:

 * libyang (see below)
 * sysrepo (see below)
 * spdlog (`libspdlog-dev`)

It also requires the `meson` package to build.

### installing libyang and sysrepo
```bash
## libyang
export SYSREPO_INSTALL="${HOME}/.local/opt/sysrepo"
curl -LO https://github.com/CESNET/libyang/archive/v1.0-r4.tar.gz
tar xf v1.0-r4.tar.gz
cd libyang-1.0-r4
mkdir build; cd build
cmake -DCMAKE_INSTALL_PREFIX=${SYSREPO_INSTALL} \
        -DCMAKE_INSTALL_LIBDIR=lib \
        -DCMAKE_BUILD_TYPE=Release \
        -DENABLE_LYD_PRIV=ON \
        -DGEN_LANGUAGE_BINDINGS=1 \
        -DGEN_PYTHON_BINDINGS=0 \
        -DGEN_CPP_BINDINGS=1 \
        ..
make install
cd ../..
export PKG_CONFIG_PATH="${SYSREPO_INSTALL}/lib/pkgconfig:${PKG_CONFIG_PATH}"
export LIBRARY_PATH="${SYSREPO_INSTALL}/lib:${LIBRARY_PATH}"

## sysrepo
### You'll need to build and install sysrepo first, **then** create the bindings
### see https://github.com/sysrepo/sysrepo/issues/1653
git clone --branch devel https://github.com/sysrepo/sysrepo.git
cd sysrepo
mkdir build-sysrepo; cd build-sysrepo
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_INSTALL_PREFIX=${SYSREPO_INSTALL} \
    -DREPOSITORY_LOC=${SYSREPO_INSTALL}/etc/sysrepo \
    -DREPO_PATH=${SYSREPO_INSTALL}/etc/sysrepo \
    -DGEN_CPP_BINDINGS=0 \
    -Wno-dev \
    ..
make install
cd ..
mkdir build-sysrepo-cpp; cd build-sysrepo-cpp
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_INSTALL_PREFIX=${SYSREPO_INSTALL} \
    -DREPOSITORY_LOC=${SYSREPO_INSTALL}/etc/sysrepo \
    -DREPO_PATH=${SYSREPO_INSTALL}/etc/sysrepo \
    -DGEN_CPP_BINDINGS=1 \
    -Wno-dev \
    ..
make install
cd ../..
```

### exports for development
```bash
SYSREPO_INSTALL="${HOME}/.local/opt/sysrepo"
export PKG_CONFIG_PATH="${SYSREPO_INSTALL}/lib/pkgconfig:${PKG_CONFIG_PATH}"
export PATH="${SYSREPO_INSTALL}/bin:${PATH}"
```

## Building the software
The [Meson](https://mesonbuild.com/Builtin-options.html) build system is used for this project.

To build, run

```bash
meson build
cd build
ninja
```

After updating the sources or the `meson.build` file, running `ninja` in the `build` directory will rebuild the project.