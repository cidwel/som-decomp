.setcpu "65816"
.segment "CODE"
.org $1D1F
map_control_0d1d1f:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
