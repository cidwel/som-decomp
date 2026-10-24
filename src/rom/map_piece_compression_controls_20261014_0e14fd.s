.setcpu "65816"
.segment "CODE"
.org $14FD
map_control_0e14fd:
    .byte $E8 ; backreference distance high bits
    .byte $61 ; distance low bit/count
