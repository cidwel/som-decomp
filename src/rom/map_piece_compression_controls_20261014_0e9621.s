.setcpu "65816"
.segment "CODE"
.org $9621
map_control_0e9621:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
