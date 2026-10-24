.setcpu "65816"
.segment "CODE"
.org $7126
map_control_0c7126:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
