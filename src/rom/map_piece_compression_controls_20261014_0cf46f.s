.setcpu "65816"
.segment "CODE"
.org $F46F
map_control_0cf46f:
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
