.setcpu "65816"
.segment "CODE"
.org $2034
map_control_0d2034:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
