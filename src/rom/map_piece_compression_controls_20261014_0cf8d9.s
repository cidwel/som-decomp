.setcpu "65816"
.segment "CODE"
.org $F8D9
map_control_0cf8d9:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
