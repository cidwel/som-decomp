.setcpu "65816"
.segment "CODE"
.org $8D3B
map_control_0f8d3b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
