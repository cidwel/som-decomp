.setcpu "65816"
.segment "CODE"
.org $96D3
map_control_0e96d3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
