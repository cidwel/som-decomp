.setcpu "65816"
.segment "CODE"
.org $EA7D
map_control_0fea7d:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
