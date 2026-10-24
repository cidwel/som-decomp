.setcpu "65816"
.segment "CODE"
.org $0DFE
map_control_0d0dfe:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
