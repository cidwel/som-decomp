.setcpu "65816"
.segment "CODE"
.org $DBCB
map_control_0edbcb:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
