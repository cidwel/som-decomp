.setcpu "65816"
.segment "CODE"
.org $86E1
map_control_0d86e1:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count
