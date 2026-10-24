.setcpu "65816"
.segment "CODE"
.org $9DED
map_control_0e9ded:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
