.setcpu "65816"
.segment "CODE"
.org $6483
map_control_0d6483:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
