.setcpu "65816"
.segment "CODE"
.org $D38E
map_control_0dd38e:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
