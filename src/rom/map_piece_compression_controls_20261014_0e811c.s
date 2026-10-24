.setcpu "65816"
.segment "CODE"
.org $811C
map_control_0e811c:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
