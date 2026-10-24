.setcpu "65816"
.segment "CODE"
.org $7A2E
map_control_0c7a2e:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
