.setcpu "65816"
.segment "CODE"
.org $55D8
map_control_0f55d8:
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
