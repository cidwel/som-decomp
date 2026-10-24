.setcpu "65816"
.segment "CODE"
.org $8A6F
map_control_0e8a6f:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
