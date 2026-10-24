.setcpu "65816"
.segment "CODE"
.org $3FC1
map_control_0d3fc1:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
