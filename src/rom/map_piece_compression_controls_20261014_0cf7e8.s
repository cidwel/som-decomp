.setcpu "65816"
.segment "CODE"
.org $F7E8
map_control_0cf7e8:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
