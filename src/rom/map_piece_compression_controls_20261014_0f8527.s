.setcpu "65816"
.segment "CODE"
.org $8527
map_control_0f8527:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
