.setcpu "65816"
.segment "CODE"
.org $542F
map_control_0c542f:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
