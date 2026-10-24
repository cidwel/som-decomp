.setcpu "65816"
.segment "CODE"
.org $4E5D
map_control_0e4e5d:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
