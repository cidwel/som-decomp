.setcpu "65816"
.segment "CODE"
.org $CC0A
map_control_0fcc0a:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
