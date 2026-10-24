.setcpu "65816"
.segment "CODE"
.org $B343
map_control_0eb343:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
