.setcpu "65816"
.segment "CODE"
.org $BA16
map_control_0eba16:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
