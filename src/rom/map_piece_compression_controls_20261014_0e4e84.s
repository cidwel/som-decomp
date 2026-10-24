.setcpu "65816"
.segment "CODE"
.org $4E84
map_control_0e4e84:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
