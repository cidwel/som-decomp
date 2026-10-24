.setcpu "65816"
.segment "CODE"
.org $601D
map_control_0e601d:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
