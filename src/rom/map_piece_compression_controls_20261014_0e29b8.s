.setcpu "65816"
.segment "CODE"
.org $29B8
map_control_0e29b8:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
