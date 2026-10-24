.setcpu "65816"
.segment "CODE"
.org $2345
map_control_0e2345:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
