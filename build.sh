#!/usr/bin/env bash

CC="g++"
SRC_FILE="kal.cpp"
BIN_FILE="bin/kal"
OPTIMIZATION="-O2"
FLAGS="-s -pipe -Wall -Werror -pedantic -fstack-protector"

SU="sudo"

function build() {
    ! [ -d bin ] && mkdir bin
    ${CC} ${OPTIMIZATION} ${FLAGS} ${SRC_FILE} -o ${BIN_FILE}
}

function install() {
    build
    ${SU} cp bin/kal /usr/local/bin
}

[ "$1" == "build" ] && build
[ "$1" == "install" ] && install
