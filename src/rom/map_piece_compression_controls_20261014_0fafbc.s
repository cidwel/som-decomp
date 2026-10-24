.setcpu "65816"
.segment "CODE"
.org $AFBC
map_control_0fafbc:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
