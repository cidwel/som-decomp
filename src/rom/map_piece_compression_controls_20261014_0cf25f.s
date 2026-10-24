.setcpu "65816"
.segment "CODE"
.org $F25F
map_control_0cf25f:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
