.setcpu "65816"
.segment "CODE"
.org $068D
map_control_0f068d:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
