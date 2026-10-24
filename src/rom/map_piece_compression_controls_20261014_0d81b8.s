.setcpu "65816"
.segment "CODE"
.org $81B8
map_control_0d81b8:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
