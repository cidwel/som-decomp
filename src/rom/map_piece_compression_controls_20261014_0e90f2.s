.setcpu "65816"
.segment "CODE"
.org $90F2
map_control_0e90f2:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
