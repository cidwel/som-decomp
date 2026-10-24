.setcpu "65816"
.segment "CODE"
.org $F9F3
map_control_0ff9f3:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
