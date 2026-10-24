.setcpu "65816"
.segment "CODE"
.org $4DD4
map_control_0e4dd4:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
