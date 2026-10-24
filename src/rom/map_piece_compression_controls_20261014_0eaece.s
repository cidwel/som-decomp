.setcpu "65816"
.segment "CODE"
.org $AECE
map_control_0eaece:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
