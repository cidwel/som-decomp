.setcpu "65816"
.segment "CODE"
.org $3E56
map_control_0e3e56:
    .byte $C7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
