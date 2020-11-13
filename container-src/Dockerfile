FROM ubuntu:16.04
RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y \
      g++-5 \
      gcc-5 \
      libgcc-5-dev \
      libsnappy-dev \
      cmake \
      make \
      libgoogle-perftools-dev \
      automake \
      libtool \
      libnuma-dev \
      libc-dev \
      groff \
      git \
      wget \
      binutils-dev \
      python \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 10 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 10 \
    && update-alternatives --install /usr/bin/gcc-ar gcc-ar /usr/bin/gcc-ar-5 10 \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 30 \
    && update-alternatives --set cc /usr/bin/gcc \
    && update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 30 \
    && update-alternatives --set c++ /usr/bin/g++ \
    && update-alternatives --install /usr/bin/ld ld /usr/bin/ld.gold 20 \
    && update-alternatives --install /usr/bin/ld ld /usr/bin/ld.bfd 10 \
    && rm -rf /var/lib/apt/lists/*

