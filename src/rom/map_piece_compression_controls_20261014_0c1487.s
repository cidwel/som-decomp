.setcpu "65816"
.segment "CODE"
.org $1487
map_control_0c1487:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
