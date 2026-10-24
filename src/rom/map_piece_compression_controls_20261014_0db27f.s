.setcpu "65816"
.segment "CODE"
.org $B27F
map_control_0db27f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $D9 ; same-value copy count/distance
