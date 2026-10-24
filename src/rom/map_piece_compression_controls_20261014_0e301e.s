.setcpu "65816"
.segment "CODE"
.org $301E
map_control_0e301e:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
