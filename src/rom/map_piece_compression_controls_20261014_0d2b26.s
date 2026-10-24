.setcpu "65816"
.segment "CODE"
.org $2B26
map_control_0d2b26:
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
