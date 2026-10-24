.setcpu "65816"
.segment "CODE"
.org $6DED
map_control_0c6ded:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
