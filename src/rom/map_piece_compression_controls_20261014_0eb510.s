.setcpu "65816"
.segment "CODE"
.org $B510
map_control_0eb510:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
