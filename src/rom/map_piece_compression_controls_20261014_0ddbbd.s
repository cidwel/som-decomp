.setcpu "65816"
.segment "CODE"
.org $DBBD
map_control_0ddbbd:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
