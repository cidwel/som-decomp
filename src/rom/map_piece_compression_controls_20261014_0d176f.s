.setcpu "65816"
.segment "CODE"
.org $176F
map_control_0d176f:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
