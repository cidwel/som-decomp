.setcpu "65816"
.segment "CODE"
.org $56DE
map_control_0e56de:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
