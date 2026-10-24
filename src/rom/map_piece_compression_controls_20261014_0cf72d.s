.setcpu "65816"
.segment "CODE"
.org $F72D
map_control_0cf72d:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
