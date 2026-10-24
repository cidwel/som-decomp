.setcpu "65816"
.segment "CODE"
.org $313D
map_control_0f313d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
