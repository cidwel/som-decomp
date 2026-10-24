.setcpu "65816"
.segment "CODE"
.org $2204
map_control_0f2204:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
