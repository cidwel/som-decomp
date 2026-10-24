.setcpu "65816"
.segment "CODE"
.org $4C11
map_control_0e4c11:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
