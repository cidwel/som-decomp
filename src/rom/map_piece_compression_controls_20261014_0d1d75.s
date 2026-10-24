.setcpu "65816"
.segment "CODE"
.org $1D75
map_control_0d1d75:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
