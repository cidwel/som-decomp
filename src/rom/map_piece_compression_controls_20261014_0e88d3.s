.setcpu "65816"
.segment "CODE"
.org $88D3
map_control_0e88d3:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
