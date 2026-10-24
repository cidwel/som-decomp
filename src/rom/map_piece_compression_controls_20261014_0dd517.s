.setcpu "65816"
.segment "CODE"
.org $D517
map_control_0dd517:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
