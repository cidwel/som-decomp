.setcpu "65816"
.segment "CODE"
.org $6AAA
map_control_0d6aaa:
    .byte $C9 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
