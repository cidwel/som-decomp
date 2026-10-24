.setcpu "65816"
.segment "CODE"
.org $49AE
map_control_0d49ae:
    .byte $EC ; backreference distance high bits
    .byte $8F ; distance low bit/count
