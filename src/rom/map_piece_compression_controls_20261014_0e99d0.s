.setcpu "65816"
.segment "CODE"
.org $99D0
map_control_0e99d0:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
