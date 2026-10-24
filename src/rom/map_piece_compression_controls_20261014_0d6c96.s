.setcpu "65816"
.segment "CODE"
.org $6C96
map_control_0d6c96:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
