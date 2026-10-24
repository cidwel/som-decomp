.setcpu "65816"
.segment "CODE"
.org $4AC4
map_control_0c4ac4:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
