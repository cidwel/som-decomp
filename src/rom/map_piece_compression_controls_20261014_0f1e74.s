.setcpu "65816"
.segment "CODE"
.org $1E74
map_control_0f1e74:
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
