.setcpu "65816"
.segment "CODE"
.org $4FE0
map_control_0d4fe0:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
