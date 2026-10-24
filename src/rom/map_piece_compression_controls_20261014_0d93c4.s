.setcpu "65816"
.segment "CODE"
.org $93C4
map_control_0d93c4:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $CC ; same-value copy count/distance
