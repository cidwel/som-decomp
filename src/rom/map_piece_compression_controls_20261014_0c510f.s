.setcpu "65816"
.segment "CODE"
.org $510F
map_control_0c510f:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
