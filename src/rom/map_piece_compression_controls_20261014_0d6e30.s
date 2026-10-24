.setcpu "65816"
.segment "CODE"
.org $6E30
map_control_0d6e30:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
