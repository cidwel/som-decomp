.setcpu "65816"
.segment "CODE"
.org $0E5F
map_control_0d0e5f:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
