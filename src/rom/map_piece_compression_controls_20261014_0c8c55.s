.setcpu "65816"
.segment "CODE"
.org $8C55
map_control_0c8c55:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
