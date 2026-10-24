.setcpu "65816"
.segment "CODE"
.org $504F
map_control_0c504f:
    .byte $E8 ; backreference distance high bits
    .byte $41 ; distance low bit/count
