.setcpu "65816"
.segment "CODE"
.org $7617
map_control_0d7617:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
