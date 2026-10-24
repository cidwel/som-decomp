.setcpu "65816"
.segment "CODE"
.org $D566
map_control_0dd566:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
