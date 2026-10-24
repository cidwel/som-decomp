.setcpu "65816"
.segment "CODE"
.org $60C6
map_control_0d60c6:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
