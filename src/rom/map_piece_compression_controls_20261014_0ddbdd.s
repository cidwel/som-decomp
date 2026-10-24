.setcpu "65816"
.segment "CODE"
.org $DBDD
map_control_0ddbdd:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
