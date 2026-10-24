.setcpu "65816"
.segment "CODE"
.org $86E2
map_control_0c86e2:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
