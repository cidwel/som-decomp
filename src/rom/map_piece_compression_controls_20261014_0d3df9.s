.setcpu "65816"
.segment "CODE"
.org $3DF9
map_control_0d3df9:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
