.setcpu "65816"
.segment "CODE"
.org $1D50
map_control_0d1d50:
    .byte $C9 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
