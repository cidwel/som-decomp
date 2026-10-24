.setcpu "65816"
.segment "CODE"
.org $0D21
map_control_0c0d21:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
