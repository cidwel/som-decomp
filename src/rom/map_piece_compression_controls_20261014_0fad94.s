.setcpu "65816"
.segment "CODE"
.org $AD94
map_control_0fad94:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
