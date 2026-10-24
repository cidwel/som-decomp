.setcpu "65816"
.segment "CODE"
.org $4E13
map_control_0e4e13:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
