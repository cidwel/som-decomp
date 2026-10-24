.setcpu "65816"
.segment "CODE"
.org $389F
map_control_0e389f:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
