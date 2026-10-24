.setcpu "65816"
.segment "CODE"
.org $DBCF
map_control_0edbcf:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
