.setcpu "65816"
.segment "CODE"
.org $54F2
map_control_0f54f2:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $D7 ; same-value copy count/distance
