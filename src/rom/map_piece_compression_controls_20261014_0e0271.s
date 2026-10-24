.setcpu "65816"
.segment "CODE"
.org $0271
map_control_0e0271:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
