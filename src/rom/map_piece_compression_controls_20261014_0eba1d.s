.setcpu "65816"
.segment "CODE"
.org $BA1D
map_control_0eba1d:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
