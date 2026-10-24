.setcpu "65816"
.segment "CODE"
.org $9735
map_control_0f9735:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
