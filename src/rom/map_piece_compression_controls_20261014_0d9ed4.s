.setcpu "65816"
.segment "CODE"
.org $9ED4
map_control_0d9ed4:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
