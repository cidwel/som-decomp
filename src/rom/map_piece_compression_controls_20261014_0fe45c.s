.setcpu "65816"
.segment "CODE"
.org $E45C
map_control_0fe45c:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
