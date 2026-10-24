.setcpu "65816"
.segment "CODE"
.org $BBEE
map_control_0ebbee:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
