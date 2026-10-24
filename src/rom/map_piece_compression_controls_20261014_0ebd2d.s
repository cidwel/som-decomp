.setcpu "65816"
.segment "CODE"
.org $BD2D
map_control_0ebd2d:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
