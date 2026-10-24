.setcpu "65816"
.segment "CODE"
.org $53B8
map_control_0d53b8:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
