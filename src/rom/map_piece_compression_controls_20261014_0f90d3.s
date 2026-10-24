.setcpu "65816"
.segment "CODE"
.org $90D3
map_control_0f90d3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
