.setcpu "65816"
.segment "CODE"
.org $EB1E
map_control_0feb1e:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
