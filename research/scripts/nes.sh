#! /usr/bin/env bash

set -o errexit

install() {
    if ! [ -x "$(command -v nes)" ]; then
        echo "Installing mednafen...!"
        sudo apt install -y mednafen
        echo "mednafen installed"
    fi
}

run() {
    install
    nes ${1}
}

run "$@"