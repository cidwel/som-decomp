.setcpu "65816"
.segment "CODE"
.org $23AB
map_control_0f23ab:
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
