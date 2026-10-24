.setcpu "65816"
.segment "CODE"
.org $F615
map_control_0cf615:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
