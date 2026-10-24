.setcpu "65816"
.segment "CODE"
.org $F7AD
map_control_0cf7ad:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
