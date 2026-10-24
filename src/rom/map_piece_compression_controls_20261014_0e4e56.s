.setcpu "65816"
.segment "CODE"
.org $4E56
map_control_0e4e56:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
