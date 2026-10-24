.setcpu "65816"
.segment "CODE"
.org $158F
map_control_0f158f:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
