.setcpu "65816"
.segment "CODE"
.org $0307
map_control_0e0307:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
