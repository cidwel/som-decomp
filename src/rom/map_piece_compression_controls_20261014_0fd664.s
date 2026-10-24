.setcpu "65816"
.segment "CODE"
.org $D664
map_control_0fd664:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
