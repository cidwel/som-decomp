.setcpu "65816"
.segment "CODE"
.org $7C81
map_control_0d7c81:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
