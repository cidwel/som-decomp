.setcpu "65816"
.segment "CODE"
.org $9810
map_control_0d9810:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
