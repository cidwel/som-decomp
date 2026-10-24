.setcpu "65816"
.segment "CODE"
.org $080E
map_control_0e080e:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
