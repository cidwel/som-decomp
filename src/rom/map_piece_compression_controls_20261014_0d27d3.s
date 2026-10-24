.setcpu "65816"
.segment "CODE"
.org $27D3
map_control_0d27d3:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
