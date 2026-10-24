.setcpu "65816"
.segment "CODE"
.org $7D20
map_control_0e7d20:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
