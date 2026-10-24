.setcpu "65816"
.segment "CODE"
.org $23BD
map_control_0f23bd:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
