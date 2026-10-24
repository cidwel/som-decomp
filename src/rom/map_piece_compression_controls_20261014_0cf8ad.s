.setcpu "65816"
.segment "CODE"
.org $F8AD
map_control_0cf8ad:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
