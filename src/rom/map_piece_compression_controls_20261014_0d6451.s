.setcpu "65816"
.segment "CODE"
.org $6451
map_control_0d6451:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
