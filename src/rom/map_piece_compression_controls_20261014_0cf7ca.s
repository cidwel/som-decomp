.setcpu "65816"
.segment "CODE"
.org $F7CA
map_control_0cf7ca:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
