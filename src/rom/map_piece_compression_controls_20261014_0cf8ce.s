.setcpu "65816"
.segment "CODE"
.org $F8CE
map_control_0cf8ce:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
