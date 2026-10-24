.setcpu "65816"
.segment "CODE"
.org $9A2F
map_control_0d9a2f:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
