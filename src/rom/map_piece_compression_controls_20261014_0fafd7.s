.setcpu "65816"
.segment "CODE"
.org $AFD7
map_control_0fafd7:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
