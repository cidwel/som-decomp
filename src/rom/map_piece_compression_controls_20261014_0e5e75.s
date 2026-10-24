.setcpu "65816"
.segment "CODE"
.org $5E75
map_control_0e5e75:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
