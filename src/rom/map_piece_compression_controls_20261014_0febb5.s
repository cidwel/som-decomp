.setcpu "65816"
.segment "CODE"
.org $EBB5
map_control_0febb5:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
