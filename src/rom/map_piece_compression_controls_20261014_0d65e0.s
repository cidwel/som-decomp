.setcpu "65816"
.segment "CODE"
.org $65E0
map_control_0d65e0:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
