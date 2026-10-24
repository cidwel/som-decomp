.setcpu "65816"
.segment "CODE"
.org $F2BF
map_control_0cf2bf:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
