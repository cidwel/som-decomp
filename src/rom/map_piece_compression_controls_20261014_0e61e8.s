.setcpu "65816"
.segment "CODE"
.org $61E8
map_control_0e61e8:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
