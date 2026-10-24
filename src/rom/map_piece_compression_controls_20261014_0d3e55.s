.setcpu "65816"
.segment "CODE"
.org $3E55
map_control_0d3e55:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
