.setcpu "65816"
.segment "CODE"
.org $9264
map_control_0f9264:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
