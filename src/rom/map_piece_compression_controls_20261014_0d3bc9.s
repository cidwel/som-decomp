.setcpu "65816"
.segment "CODE"
.org $3BC9
map_control_0d3bc9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
