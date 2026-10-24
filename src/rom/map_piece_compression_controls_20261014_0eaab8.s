.setcpu "65816"
.segment "CODE"
.org $AAB8
map_control_0eaab8:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
