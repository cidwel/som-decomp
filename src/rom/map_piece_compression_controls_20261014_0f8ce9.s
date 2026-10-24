.setcpu "65816"
.segment "CODE"
.org $8CE9
map_control_0f8ce9:
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
