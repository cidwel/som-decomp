.setcpu "65816"
.segment "CODE"
.org $CF6A
map_control_0fcf6a:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
