.setcpu "65816"
.segment "CODE"
.org $982C
map_control_0e982c:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
