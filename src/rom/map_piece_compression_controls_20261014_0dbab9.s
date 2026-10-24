.setcpu "65816"
.segment "CODE"
.org $BAB9
map_control_0dbab9:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
