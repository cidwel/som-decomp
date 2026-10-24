.setcpu "65816"
.segment "CODE"
.org $1D17
map_control_0d1d17:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
