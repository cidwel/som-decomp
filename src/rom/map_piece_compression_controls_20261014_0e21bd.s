.setcpu "65816"
.segment "CODE"
.org $21BD
map_control_0e21bd:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
