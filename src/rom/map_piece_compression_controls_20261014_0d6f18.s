.setcpu "65816"
.segment "CODE"
.org $6F18
map_control_0d6f18:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
