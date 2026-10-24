.setcpu "65816"
.segment "CODE"
.org $1629
map_control_0f1629:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
