.setcpu "65816"
.segment "CODE"
.org $4C9F
map_control_0e4c9f:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
