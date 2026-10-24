.setcpu "65816"
.segment "CODE"
.org $4C31
map_control_0d4c31:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
