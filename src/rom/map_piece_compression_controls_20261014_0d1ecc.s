.setcpu "65816"
.segment "CODE"
.org $1ECC
map_control_0d1ecc:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
