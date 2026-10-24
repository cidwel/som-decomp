.setcpu "65816"
.segment "CODE"
.org $4C45
map_control_0d4c45:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
