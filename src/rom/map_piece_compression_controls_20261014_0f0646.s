.setcpu "65816"
.segment "CODE"
.org $0646
map_control_0f0646:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
