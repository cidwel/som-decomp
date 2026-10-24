.setcpu "65816"
.segment "CODE"
.org $30D3
map_control_0f30d3:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
