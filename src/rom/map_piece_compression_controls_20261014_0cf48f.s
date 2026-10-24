.setcpu "65816"
.segment "CODE"
.org $F48F
map_control_0cf48f:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
