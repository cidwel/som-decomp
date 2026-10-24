.setcpu "65816"
.segment "CODE"
.org $390F
map_control_0d390f:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
