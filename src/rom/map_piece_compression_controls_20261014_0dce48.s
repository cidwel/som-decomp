.setcpu "65816"
.segment "CODE"
.org $CE48
map_control_0dce48:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
