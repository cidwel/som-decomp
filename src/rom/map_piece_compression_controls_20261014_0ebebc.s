.setcpu "65816"
.segment "CODE"
.org $BEBC
map_control_0ebebc:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
