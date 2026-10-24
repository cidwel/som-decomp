.setcpu "65816"
.segment "CODE"
.org $D51A
map_control_0dd51a:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
