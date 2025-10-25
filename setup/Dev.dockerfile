FROM ubuntu:25.04

RUN apt-get update && apt-get install -y \
    build-essential curl git neovim clang-format \
    software-properties-common openssl libssl-dev ca-certificates

RUN add-apt-repository ppa:xmake-io/xmake && apt-get update && \
    apt-get install -y xmake