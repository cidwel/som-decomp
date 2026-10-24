.setcpu "65816"
.segment "CODE"
.org $7BCF
map_control_0e7bcf:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
