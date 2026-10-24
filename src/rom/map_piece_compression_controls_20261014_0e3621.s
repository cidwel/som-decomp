.setcpu "65816"
.segment "CODE"
.org $3621
map_control_0e3621:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
