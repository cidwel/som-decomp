.setcpu "65816"
.segment "CODE"
.org $BCAF
map_control_0ebcaf:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
