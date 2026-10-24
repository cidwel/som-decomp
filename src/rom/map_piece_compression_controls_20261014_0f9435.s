.setcpu "65816"
.segment "CODE"
.org $9435
map_control_0f9435:
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
