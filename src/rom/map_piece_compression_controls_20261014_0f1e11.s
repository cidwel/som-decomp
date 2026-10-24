.setcpu "65816"
.segment "CODE"
.org $1E11
map_control_0f1e11:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
