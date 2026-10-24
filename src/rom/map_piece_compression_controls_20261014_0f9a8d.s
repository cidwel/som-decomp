.setcpu "65816"
.segment "CODE"
.org $9A8D
map_control_0f9a8d:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
