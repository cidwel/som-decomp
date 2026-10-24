.setcpu "65816"
.segment "CODE"
.org $41B8
map_control_0e41b8:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
