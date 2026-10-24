.setcpu "65816"
.segment "CODE"
.org $86D0
map_control_0c86d0:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
