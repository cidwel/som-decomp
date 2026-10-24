.setcpu "65816"
.segment "CODE"
.org $3579
map_control_0d3579:
    .byte $DB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
