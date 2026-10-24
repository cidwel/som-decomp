.setcpu "65816"
.segment "CODE"
.org $71F8
map_control_0f71f8:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
