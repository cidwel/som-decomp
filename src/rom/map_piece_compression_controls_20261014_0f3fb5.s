.setcpu "65816"
.segment "CODE"
.org $3FB5
map_control_0f3fb5:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
