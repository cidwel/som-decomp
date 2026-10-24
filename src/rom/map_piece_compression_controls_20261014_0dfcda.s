.setcpu "65816"
.segment "CODE"
.org $FCDA
map_control_0dfcda:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
