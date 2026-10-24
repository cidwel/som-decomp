.setcpu "65816"
.segment "CODE"
.org $CFCD
map_control_0ecfcd:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
