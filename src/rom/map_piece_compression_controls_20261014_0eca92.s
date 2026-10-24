.setcpu "65816"
.segment "CODE"
.org $CA92
map_control_0eca92:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
