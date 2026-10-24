.setcpu "65816"
.segment "CODE"
.org $E074
map_control_0de074:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
