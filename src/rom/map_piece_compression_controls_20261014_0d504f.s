.setcpu "65816"
.segment "CODE"
.org $504F
map_control_0d504f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
