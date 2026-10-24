.setcpu "65816"
.segment "CODE"
.org $BADE
map_control_0dbade:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
