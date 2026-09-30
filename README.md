# Corne keymaps

My custom keymaps which is heavily inspired by [Miryoku](https://github.com/manna-harbour/miryoku).
Some differences are:

- Number, Symbol, and Function layer are right-hand layers
- arrows are above `WASD`
- modifier order is `Alt`, `Ctrl`, `Shift`, `Super`

## Installation

### Compile

Set up [QMK](https://docs.qmk.fm/newbs_getting_started).
This repository is a [QMK userspace](https://docs.qmk.fm/feature_userspace).
From the repository root run

```sh
qmk userspace-compile
```

This reads [`qmk.json`](qmk.json) and builds every target.
The resulting `.uf2` files are written to the repository root.

### Flash

The Aurora uses the same firmware for both halves.
The Halcyon halves each run their own firmware, so the two halves get different images.

Enter the bootloader, then copy the appropriate `.uf2` onto the drive that appears.

## Features

- [Miryoku](https://github.com/manna-harbour/miryoku) based
- [timeless home row mods](https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/)
- [mod-tap](https://docs.qmk.fm/mod_tap)
- [caps word](https://docs.qmk.fm/feature_caps_word)
- multiple layers with Colemak as base
- RALT layer for Umlaute, ß, €
- Halcyon rotary encoder
- Halcyon Cirque trackpad
