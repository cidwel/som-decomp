.setcpu "65816"
.segment "CODE"
.org $CEA4
map_control_0dcea4:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
