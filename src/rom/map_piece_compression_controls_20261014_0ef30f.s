.setcpu "65816"
.segment "CODE"
.org $F30F
map_control_0ef30f:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
