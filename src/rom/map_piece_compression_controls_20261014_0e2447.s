.setcpu "65816"
.segment "CODE"
.org $2447
map_control_0e2447:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
