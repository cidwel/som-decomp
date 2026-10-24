.setcpu "65816"
.segment "CODE"
.org $AF2D
map_control_0daf2d:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
