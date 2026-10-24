.setcpu "65816"
.segment "CODE"
.org $DA5B
map_control_0eda5b:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
