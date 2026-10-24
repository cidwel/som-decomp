.setcpu "65816"
.segment "CODE"
.org $49CC
map_control_0e49cc:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
