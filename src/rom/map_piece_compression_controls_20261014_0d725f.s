.setcpu "65816"
.segment "CODE"
.org $725F
map_control_0d725f:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
