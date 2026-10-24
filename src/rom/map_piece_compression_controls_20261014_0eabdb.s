.setcpu "65816"
.segment "CODE"
.org $ABDB
map_control_0eabdb:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
