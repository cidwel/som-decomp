.setcpu "65816"
.segment "CODE"
.org $F7DB
map_control_0cf7db:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
