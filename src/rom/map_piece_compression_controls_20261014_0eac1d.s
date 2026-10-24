.setcpu "65816"
.segment "CODE"
.org $AC1D
map_control_0eac1d:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $8E ; distance low bit/count
