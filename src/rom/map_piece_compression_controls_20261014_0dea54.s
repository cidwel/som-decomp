.setcpu "65816"
.segment "CODE"
.org $EA54
map_control_0dea54:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
