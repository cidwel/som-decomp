.setcpu "65816"
.segment "CODE"
.org $5B19
map_control_0c5b19:
    .byte $C3 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
