.setcpu "65816"
.segment "CODE"
.org $B615
map_control_0eb615:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
