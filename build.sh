#!/usr/bin/env bash

rm -rf build

coverage() {
    cmake --preset=dev-coverage
    cmake --build build/coverage/ --config Debug
    cmake --build build/coverage/ --target coverage
}

sanitize() {
    cmake --preset=ci-sanitize -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
    cmake --build build/sanitize -j 2
    (cd build/sanitize && ctest --output-on-failure --no-tests=error -j 2)
}

sanitize
