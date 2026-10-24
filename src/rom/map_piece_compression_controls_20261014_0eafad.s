.setcpu "65816"
.segment "CODE"
.org $AFAD
map_control_0eafad:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
