.setcpu "65816"
.segment "CODE"
.org $3B9D
map_control_0d3b9d:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
