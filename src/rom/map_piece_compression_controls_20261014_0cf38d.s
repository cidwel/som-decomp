.setcpu "65816"
.segment "CODE"
.org $F38D
map_control_0cf38d:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
