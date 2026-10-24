.setcpu "65816"
.segment "CODE"
.org $1A3B
map_control_0e1a3b:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
