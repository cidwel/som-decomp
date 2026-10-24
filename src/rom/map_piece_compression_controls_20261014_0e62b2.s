.setcpu "65816"
.segment "CODE"
.org $62B2
map_control_0e62b2:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
