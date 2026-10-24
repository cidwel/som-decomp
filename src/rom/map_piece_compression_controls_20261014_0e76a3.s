.setcpu "65816"
.segment "CODE"
.org $76A3
map_control_0e76a3:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
