.setcpu "65816"
.segment "CODE"
.org $42B7
map_control_0d42b7:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
