.setcpu "65816"
.segment "CODE"
.org $6031
map_control_0e6031:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
