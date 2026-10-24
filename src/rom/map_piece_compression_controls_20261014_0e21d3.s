.setcpu "65816"
.segment "CODE"
.org $21D3
map_control_0e21d3:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
