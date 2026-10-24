.setcpu "65816"
.segment "CODE"
.org $BABE
map_control_0ebabe:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
