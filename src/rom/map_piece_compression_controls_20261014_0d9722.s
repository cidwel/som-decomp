.setcpu "65816"
.segment "CODE"
.org $9722
map_control_0d9722:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
