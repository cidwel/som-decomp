.setcpu "65816"
.segment "CODE"
.org $44D2
map_control_0d44d2:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
