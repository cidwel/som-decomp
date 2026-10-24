.setcpu "65816"
.segment "CODE"
.org $3917
map_control_0f3917:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
