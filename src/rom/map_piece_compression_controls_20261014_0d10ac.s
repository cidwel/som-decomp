.setcpu "65816"
.segment "CODE"
.org $10AC
map_control_0d10ac:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
