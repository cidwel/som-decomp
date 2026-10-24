.setcpu "65816"
.segment "CODE"
.org $E8C9
map_control_0fe8c9:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
