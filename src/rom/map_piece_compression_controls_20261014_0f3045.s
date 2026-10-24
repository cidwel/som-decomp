.setcpu "65816"
.segment "CODE"
.org $3045
map_control_0f3045:
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
