.setcpu "65816"
.segment "CODE"
.org $1480
map_control_0f1480:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
