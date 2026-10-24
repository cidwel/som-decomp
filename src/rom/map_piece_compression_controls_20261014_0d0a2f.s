.setcpu "65816"
.segment "CODE"
.org $0A2F
map_control_0d0a2f:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
