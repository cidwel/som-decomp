.setcpu "65816"
.segment "CODE"
.org $95D6
map_control_0e95d6:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
