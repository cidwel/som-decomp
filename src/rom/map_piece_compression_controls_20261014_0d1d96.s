.setcpu "65816"
.segment "CODE"
.org $1D96
map_control_0d1d96:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
