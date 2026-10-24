.setcpu "65816"
.segment "CODE"
.org $8920
map_control_0f8920:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
