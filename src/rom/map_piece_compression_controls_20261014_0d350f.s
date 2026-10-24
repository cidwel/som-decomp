.setcpu "65816"
.segment "CODE"
.org $350F
map_control_0d350f:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
