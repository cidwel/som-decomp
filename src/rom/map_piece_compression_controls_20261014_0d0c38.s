.setcpu "65816"
.segment "CODE"
.org $0C38
map_control_0d0c38:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
