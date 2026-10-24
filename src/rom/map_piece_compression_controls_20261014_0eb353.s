.setcpu "65816"
.segment "CODE"
.org $B353
map_control_0eb353:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
