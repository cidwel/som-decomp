.setcpu "65816"
.segment "CODE"
.org $4C19
map_control_0c4c19:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
