.setcpu "65816"
.segment "CODE"
.org $7374
map_control_0d7374:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
