.setcpu "65816"
.segment "CODE"
.org $5427
map_control_0e5427:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
