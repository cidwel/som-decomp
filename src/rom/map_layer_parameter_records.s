; Numeric map-layer configuration: mode flags, two literal parameter pairs, paired selectors.
.setcpu "65816"
.segment "CODE"
.org $0000
map_layer_parameter_records:
; Record 0: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 1: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 1 | (9 << 4), 0 | (0 << 4)
; Record 2: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 11 | (0 << 4), 0 | (0 << 4)
; Record 3: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 0 | (11 << 4), 0 | (0 << 4)
; Record 4: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 0 | (3 << 4), 0 | (0 << 4)
; Record 5: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %00001010, 0 | (0 << 4), 8 | (8 << 4), 0 | (0 << 4)
; Record 6: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %01011010, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 7: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111010, 0 | (0 << 4), 2 | (2 << 4), 0 | (0 << 4)
; Record 8: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101111, 2 | (2 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 9: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101111, 8 | (2 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 10: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111010, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 11: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %01010101, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 12: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 4 | (0 << 4), 0 | (0 << 4)
; Record 13: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 12 | (0 << 4), 0 | (0 << 4)
; Record 14: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %00001010, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 15: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %01011010, 0 | (0 << 4), 9 | (0 << 4), 0 | (0 << 4)
; Record 16: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %01011010, 0 | (0 << 4), 1 | (0 << 4), 0 | (0 << 4)
; Record 17: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %01011010, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 18: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %10101010, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 19: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %01011010, 0 | (0 << 4), 0 | (0 << 4), 0 | (0 << 4)
; Record 20: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 21: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 22: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 23: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 24: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 25: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 26: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 27: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 28: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 29: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 30: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 31: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 32: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 33: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 34: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 35: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 36: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 37: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 38: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 39: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 40: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 41: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 42: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 43: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 44: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 45: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 46: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 47: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 48: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 49: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 50: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 51: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 52: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 53: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 54: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 55: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 56: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 57: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 58: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 59: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 60: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 61: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 62: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
; Record 63: four 2-bit modes; two nibble pairs; paired-selector nibbles.
    .byte %11111111, 15 | (15 << 4), 15 | (15 << 4), 15 | (15 << 4)
