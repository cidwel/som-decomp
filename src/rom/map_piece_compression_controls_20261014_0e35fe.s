.setcpu "65816"
.segment "CODE"
.org $35FE
map_control_0e35fe:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
