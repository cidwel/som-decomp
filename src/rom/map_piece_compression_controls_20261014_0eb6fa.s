.setcpu "65816"
.segment "CODE"
.org $B6FA
map_control_0eb6fa:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
