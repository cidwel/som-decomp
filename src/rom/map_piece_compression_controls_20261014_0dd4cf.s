.setcpu "65816"
.segment "CODE"
.org $D4CF
map_control_0dd4cf:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
