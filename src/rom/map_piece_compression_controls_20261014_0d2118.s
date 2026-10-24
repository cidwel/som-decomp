.setcpu "65816"
.segment "CODE"
.org $2118
map_control_0d2118:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
