.setcpu "65816"
.segment "CODE"
.org $CCF0
map_control_0dccf0:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
