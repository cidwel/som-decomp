.setcpu "65816"
.segment "CODE"
.org $6F79
map_control_0c6f79:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
