.setcpu "65816"
.segment "CODE"
.org $CFEE
map_control_0ecfee:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
