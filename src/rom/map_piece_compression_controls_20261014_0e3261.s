.setcpu "65816"
.segment "CODE"
.org $3261
map_control_0e3261:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
