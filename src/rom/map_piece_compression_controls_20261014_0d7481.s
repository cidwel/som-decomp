.setcpu "65816"
.segment "CODE"
.org $7481
map_control_0d7481:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
