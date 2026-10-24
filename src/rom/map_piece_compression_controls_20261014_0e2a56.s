.setcpu "65816"
.segment "CODE"
.org $2A56
map_control_0e2a56:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
