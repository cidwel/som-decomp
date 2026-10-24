.setcpu "65816"
.segment "CODE"
.org $BC93
map_control_0ebc93:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
