.setcpu "65816"
.segment "CODE"
.org $9D3A
map_control_0e9d3a:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
