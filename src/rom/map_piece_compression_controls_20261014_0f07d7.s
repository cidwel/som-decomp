.setcpu "65816"
.segment "CODE"
.org $07D7
map_control_0f07d7:
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
