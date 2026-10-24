.setcpu "65816"
.segment "CODE"
.org $75E7
map_control_0c75e7:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
