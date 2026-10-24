.setcpu "65816"
.segment "CODE"
.org $4C38
map_control_0d4c38:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
