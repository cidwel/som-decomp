.setcpu "65816"
.segment "CODE"
.org $3C9B
map_control_0e3c9b:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
