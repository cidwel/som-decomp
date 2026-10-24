.setcpu "65816"
.segment "CODE"
.org $411F
map_control_0e411f:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
