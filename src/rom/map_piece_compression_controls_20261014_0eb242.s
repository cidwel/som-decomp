.setcpu "65816"
.segment "CODE"
.org $B242
map_control_0eb242:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
