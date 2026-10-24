.setcpu "65816"
.segment "CODE"
.org $0D3F
map_control_0c0d3f:
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
