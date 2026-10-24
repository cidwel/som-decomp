.setcpu "65816"
.segment "CODE"
.org $3B4F
map_control_0d3b4f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
