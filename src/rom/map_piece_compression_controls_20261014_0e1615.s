.setcpu "65816"
.segment "CODE"
.org $1615
map_control_0e1615:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
