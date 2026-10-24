.setcpu "65816"
.segment "CODE"
.org $4A78
map_control_0d4a78:
    .byte $EA ; backreference distance high bits
    .byte $05 ; distance low bit/count
