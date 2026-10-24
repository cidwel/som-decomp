.setcpu "65816"
.segment "CODE"
.org $F8B9
map_control_0cf8b9:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
