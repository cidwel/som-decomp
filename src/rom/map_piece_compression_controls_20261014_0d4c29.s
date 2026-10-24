.setcpu "65816"
.segment "CODE"
.org $4C29
map_control_0d4c29:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
