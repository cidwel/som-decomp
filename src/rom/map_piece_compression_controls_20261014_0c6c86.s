.setcpu "65816"
.segment "CODE"
.org $6C86
map_control_0c6c86:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
