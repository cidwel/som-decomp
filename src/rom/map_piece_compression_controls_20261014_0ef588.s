.setcpu "65816"
.segment "CODE"
.org $F588
map_control_0ef588:
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
