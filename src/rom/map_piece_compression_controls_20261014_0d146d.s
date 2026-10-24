.setcpu "65816"
.segment "CODE"
.org $146D
map_control_0d146d:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
