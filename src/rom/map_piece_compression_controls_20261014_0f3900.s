.setcpu "65816"
.segment "CODE"
.org $3900
map_control_0f3900:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
