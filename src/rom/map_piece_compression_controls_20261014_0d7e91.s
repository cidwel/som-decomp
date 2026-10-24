.setcpu "65816"
.segment "CODE"
.org $7E91
map_control_0d7e91:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
