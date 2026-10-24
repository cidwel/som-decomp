.setcpu "65816"
.segment "CODE"
.org $FFB9
map_control_0effb9:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
