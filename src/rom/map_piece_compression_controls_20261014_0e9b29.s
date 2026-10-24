.setcpu "65816"
.segment "CODE"
.org $9B29
map_control_0e9b29:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
