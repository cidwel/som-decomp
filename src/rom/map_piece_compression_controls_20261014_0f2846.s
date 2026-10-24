.setcpu "65816"
.segment "CODE"
.org $2846
map_control_0f2846:
    .byte $D2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
