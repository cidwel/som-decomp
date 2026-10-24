.setcpu "65816"
.segment "CODE"
.org $7F58
map_control_0c7f58:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
