.setcpu "65816"
.segment "CODE"
.org $7C6D
map_control_0c7c6d:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
