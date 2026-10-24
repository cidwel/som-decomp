.setcpu "65816"
.segment "CODE"
.org $F7F9
map_control_0cf7f9:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
