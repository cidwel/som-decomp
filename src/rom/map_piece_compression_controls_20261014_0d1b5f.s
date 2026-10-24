.setcpu "65816"
.segment "CODE"
.org $1B5F
map_control_0d1b5f:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
