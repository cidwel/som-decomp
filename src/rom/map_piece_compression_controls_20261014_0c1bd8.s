.setcpu "65816"
.segment "CODE"
.org $1BD8
map_control_0c1bd8:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
