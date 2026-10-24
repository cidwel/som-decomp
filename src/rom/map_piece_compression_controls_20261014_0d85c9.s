.setcpu "65816"
.segment "CODE"
.org $85C9
map_control_0d85c9:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
