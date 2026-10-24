.setcpu "65816"
.segment "CODE"
.org $FA31
map_control_0ffa31:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
