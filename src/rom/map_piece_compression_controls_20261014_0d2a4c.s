.setcpu "65816"
.segment "CODE"
.org $2A4C
map_control_0d2a4c:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
