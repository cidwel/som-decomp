.setcpu "65816"
.segment "CODE"
.org $2223
map_control_0e2223:
    .byte $D7 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
