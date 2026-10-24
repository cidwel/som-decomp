.setcpu "65816"
.segment "CODE"
.org $8D91
map_control_0e8d91:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
