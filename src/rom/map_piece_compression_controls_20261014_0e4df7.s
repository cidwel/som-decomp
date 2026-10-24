.setcpu "65816"
.segment "CODE"
.org $4DF7
map_control_0e4df7:
    .byte $EB ; backreference distance high bits
    .byte $8E ; distance low bit/count
