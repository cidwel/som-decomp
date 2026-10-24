.setcpu "65816"
.segment "CODE"
.org $349A
map_control_0d349a:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
