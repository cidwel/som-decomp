.setcpu "65816"
.segment "CODE"
.org $9C99
map_control_0d9c99:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
