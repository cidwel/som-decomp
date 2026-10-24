.setcpu "65816"
.segment "CODE"
.org $453F
map_control_0d453f:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
