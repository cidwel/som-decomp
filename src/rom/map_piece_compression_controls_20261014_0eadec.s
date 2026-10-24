.setcpu "65816"
.segment "CODE"
.org $ADEC
map_control_0eadec:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
