.setcpu "65816"
.segment "CODE"
.org $D63C
map_control_0ed63c:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
