.setcpu "65816"
.segment "CODE"
.org $221E
map_control_0e221e:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
