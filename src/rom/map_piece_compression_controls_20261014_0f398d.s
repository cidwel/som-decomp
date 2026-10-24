.setcpu "65816"
.segment "CODE"
.org $398D
map_control_0f398d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
