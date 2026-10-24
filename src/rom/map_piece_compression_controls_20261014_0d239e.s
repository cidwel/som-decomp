.setcpu "65816"
.segment "CODE"
.org $239E
map_control_0d239e:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
