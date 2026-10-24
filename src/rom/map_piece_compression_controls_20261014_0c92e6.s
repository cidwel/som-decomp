.setcpu "65816"
.segment "CODE"
.org $92E6
map_control_0c92e6:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
