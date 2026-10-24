.setcpu "65816"
.segment "CODE"
.org $5903
map_control_0f5903:
    .byte $D2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
