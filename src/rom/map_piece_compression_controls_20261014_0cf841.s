.setcpu "65816"
.segment "CODE"
.org $F841
map_control_0cf841:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
