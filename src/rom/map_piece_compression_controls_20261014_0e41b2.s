.setcpu "65816"
.segment "CODE"
.org $41B2
map_control_0e41b2:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
