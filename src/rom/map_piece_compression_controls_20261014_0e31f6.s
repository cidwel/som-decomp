.setcpu "65816"
.segment "CODE"
.org $31F6
map_control_0e31f6:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
