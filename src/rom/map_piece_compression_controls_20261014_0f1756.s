.setcpu "65816"
.segment "CODE"
.org $1756
map_control_0f1756:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
