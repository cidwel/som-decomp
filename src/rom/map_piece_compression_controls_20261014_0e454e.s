.setcpu "65816"
.segment "CODE"
.org $454E
map_control_0e454e:
    .byte $C4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
