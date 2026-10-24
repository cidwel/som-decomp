.setcpu "65816"
.segment "CODE"
.org $EF6E
map_control_0fef6e:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
