.setcpu "65816"
.segment "CODE"
.org $6F3C
map_control_0d6f3c:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
