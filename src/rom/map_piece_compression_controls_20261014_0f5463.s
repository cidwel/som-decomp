.setcpu "65816"
.segment "CODE"
.org $5463
map_control_0f5463:
    .byte $C7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
