.setcpu "65816"
.segment "CODE"
.org $4401
map_control_0d4401:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
