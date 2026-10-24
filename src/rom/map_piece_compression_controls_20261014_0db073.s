.setcpu "65816"
.segment "CODE"
.org $B073
map_control_0db073:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
