.setcpu "65816"
.segment "CODE"
.org $BCAF
map_control_0fbcaf:
    .byte $E9 ; backreference distance high bits
    .byte $08 ; distance low bit/count
