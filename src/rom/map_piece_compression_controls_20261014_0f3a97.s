.setcpu "65816"
.segment "CODE"
.org $3A97
map_control_0f3a97:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
