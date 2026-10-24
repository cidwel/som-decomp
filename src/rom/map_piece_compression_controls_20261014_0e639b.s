.setcpu "65816"
.segment "CODE"
.org $639B
map_control_0e639b:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
