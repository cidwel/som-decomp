.setcpu "65816"
.segment "CODE"
.org $5A05
map_control_0e5a05:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
