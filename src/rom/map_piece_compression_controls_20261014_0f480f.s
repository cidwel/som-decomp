.setcpu "65816"
.segment "CODE"
.org $480F
map_control_0f480f:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
