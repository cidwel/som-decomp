.setcpu "65816"
.segment "CODE"
.org $DBDB
map_control_0edbdb:
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
