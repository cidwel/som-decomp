.setcpu "65816"
.segment "CODE"
.org $2380
map_control_0d2380:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
