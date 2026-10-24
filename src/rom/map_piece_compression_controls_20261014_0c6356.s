.setcpu "65816"
.segment "CODE"
.org $6356
map_control_0c6356:
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
