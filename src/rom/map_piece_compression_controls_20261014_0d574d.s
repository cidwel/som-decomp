.setcpu "65816"
.segment "CODE"
.org $574D
map_control_0d574d:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
