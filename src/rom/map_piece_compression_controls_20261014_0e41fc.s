.setcpu "65816"
.segment "CODE"
.org $41FC
map_control_0e41fc:
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
