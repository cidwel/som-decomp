.setcpu "65816"
.segment "CODE"
.org $BB56
map_control_0ebb56:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
