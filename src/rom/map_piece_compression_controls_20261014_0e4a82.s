.setcpu "65816"
.segment "CODE"
.org $4A82
map_control_0e4a82:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
