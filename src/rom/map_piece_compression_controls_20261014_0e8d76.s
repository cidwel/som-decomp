.setcpu "65816"
.segment "CODE"
.org $8D76
map_control_0e8d76:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
