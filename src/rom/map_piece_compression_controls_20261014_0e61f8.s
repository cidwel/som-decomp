.setcpu "65816"
.segment "CODE"
.org $61F8
map_control_0e61f8:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
