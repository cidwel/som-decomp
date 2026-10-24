.setcpu "65816"
.segment "CODE"
.org $38E2
map_control_0f38e2:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
