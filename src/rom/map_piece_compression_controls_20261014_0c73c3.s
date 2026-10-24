.setcpu "65816"
.segment "CODE"
.org $73C3
map_control_0c73c3:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
