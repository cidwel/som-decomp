.setcpu "65816"
.segment "CODE"
.org $0C49
map_control_0e0c49:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
