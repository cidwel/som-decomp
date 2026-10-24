.setcpu "65816"
.segment "CODE"
.org $5740
map_control_0f5740:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
