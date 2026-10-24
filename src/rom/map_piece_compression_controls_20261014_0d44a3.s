.setcpu "65816"
.segment "CODE"
.org $44A3
map_control_0d44a3:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
