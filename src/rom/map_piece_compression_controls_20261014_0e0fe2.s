.setcpu "65816"
.segment "CODE"
.org $0FE2
map_control_0e0fe2:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
