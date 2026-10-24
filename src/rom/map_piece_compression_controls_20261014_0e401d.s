.setcpu "65816"
.segment "CODE"
.org $401D
map_control_0e401d:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
