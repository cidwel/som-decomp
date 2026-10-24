.setcpu "65816"
.segment "CODE"
.org $4705
map_control_0d4705:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
