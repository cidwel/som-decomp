.setcpu "65816"
.segment "CODE"
.org $664F
map_control_0f664f:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
