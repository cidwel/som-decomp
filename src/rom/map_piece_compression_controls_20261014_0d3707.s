.setcpu "65816"
.segment "CODE"
.org $3707
map_control_0d3707:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
