.setcpu "65816"
.segment "CODE"
.org $9E0F
map_control_0d9e0f:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
