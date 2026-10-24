.setcpu "65816"
.segment "CODE"
.org $82B5
map_control_0c82b5:
    .byte $EC ; backreference distance high bits
    .byte $CD ; distance low bit/count
