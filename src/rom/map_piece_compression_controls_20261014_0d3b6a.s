.setcpu "65816"
.segment "CODE"
.org $3B6A
map_control_0d3b6a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
