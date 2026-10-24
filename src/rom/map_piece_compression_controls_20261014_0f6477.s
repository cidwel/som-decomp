.setcpu "65816"
.segment "CODE"
.org $6477
map_control_0f6477:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
