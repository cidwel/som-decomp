.setcpu "65816"
.segment "CODE"
.org $0E2A
map_control_0d0e2a:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
