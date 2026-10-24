.setcpu "65816"
.segment "CODE"
.org $EAB0
map_control_0feab0:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
