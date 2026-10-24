.setcpu "65816"
.segment "CODE"
.org $5542
map_control_0f5542:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
