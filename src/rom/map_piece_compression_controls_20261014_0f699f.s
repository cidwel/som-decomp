.setcpu "65816"
.segment "CODE"
.org $699F
map_control_0f699f:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
