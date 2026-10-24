.setcpu "65816"
.segment "CODE"
.org $298D
map_control_0c298d:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
