.setcpu "65816"
.segment "CODE"
.org $788F
map_control_0f788f:
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
