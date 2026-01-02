# OpenBlink XIAO nRF54L15 Sense

[![English](https://img.shields.io/badge/language-English-blue.svg)](README.md)
[![中文](https://img.shields.io/badge/language-中文-red.svg)](README.zh-CN.md)
[![日本語](https://img.shields.io/badge/language-日本語-green.svg)](README.ja.md)
[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/uist1idrju3i/openblink_XIAO_nRF54L15_Sense)

## What is OpenBlink

**_OpenBlink_** is an open source project forked from **_ViXion Blink_**.

- Ruby, a highly productive lightweight language, can be used to develop embedded devices.
- Program rewriting and debugging console are completely wireless. (BluetoothLE)
- Rewriting time is less than 0.1 second and does not involve a microprocessor restart. (We call it "Blink".)

## How to Get OpenBlink

To clone the repository and initialize the submodules, run the following commands:

```console
$ git clone https://github.com/uist1idrju3i/openblink_XIAO_nRF54L15_Sense.git
$ git submodule init
$ git submodule update

$ brew install ccache
$ brew install openocd
$ west flash
```

Please refer to https://wiki.seeedstudio.com/xiao_nrf54l15_sense_getting_started/#download-burn-in-plug-in

## Documentation

For more detailed documentation, please check the [doc](./doc)

For AI-powered comprehensive documentation that helps you understand the codebase, visit [DeepWiki](https://deepwiki.com/uist1idrju3i/openblink_XIAO_nRF54L15_Sense)

## Verified Hardware

The following hardware platforms have been tested with OpenBlink:

- Seeed XIAO nRF54L15 (Board target: xiao_nrf54l15/nrf54l15/cpuapp)

## Development Environment Versions

- nRF Connect SDK toolchain v3.2.1
- nRF Connect SDK v3.2.1
