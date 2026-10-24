.setcpu "65816"
.segment "CODE"
.org $4124
map_control_0d4124:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
