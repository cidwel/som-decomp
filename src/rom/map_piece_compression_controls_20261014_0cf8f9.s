.setcpu "65816"
.segment "CODE"
.org $F8F9
map_control_0cf8f9:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
