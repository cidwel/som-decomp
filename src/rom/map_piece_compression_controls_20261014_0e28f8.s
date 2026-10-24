.setcpu "65816"
.segment "CODE"
.org $28F8
map_control_0e28f8:
    .byte $D2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
