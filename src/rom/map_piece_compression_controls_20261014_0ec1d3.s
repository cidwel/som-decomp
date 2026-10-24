.setcpu "65816"
.segment "CODE"
.org $C1D3
map_control_0ec1d3:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
