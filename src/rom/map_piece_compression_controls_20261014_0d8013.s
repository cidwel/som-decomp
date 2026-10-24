.setcpu "65816"
.segment "CODE"
.org $8013
map_control_0d8013:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
