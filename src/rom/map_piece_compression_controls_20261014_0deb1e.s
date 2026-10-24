.setcpu "65816"
.segment "CODE"
.org $EB1E
map_control_0deb1e:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
