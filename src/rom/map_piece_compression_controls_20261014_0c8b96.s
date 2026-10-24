.setcpu "65816"
.segment "CODE"
.org $8B96
map_control_0c8b96:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
