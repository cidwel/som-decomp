.setcpu "65816"
.segment "CODE"
.org $D07C
map_control_0dd07c:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
