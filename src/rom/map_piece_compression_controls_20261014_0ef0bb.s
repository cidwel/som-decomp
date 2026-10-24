.setcpu "65816"
.segment "CODE"
.org $F0BB
map_control_0ef0bb:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
