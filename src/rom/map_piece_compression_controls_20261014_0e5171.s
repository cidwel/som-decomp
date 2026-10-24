.setcpu "65816"
.segment "CODE"
.org $5171
map_control_0e5171:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
