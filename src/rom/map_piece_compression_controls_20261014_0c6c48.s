.setcpu "65816"
.segment "CODE"
.org $6C48
map_control_0c6c48:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
