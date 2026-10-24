.setcpu "65816"
.segment "CODE"
.org $D305
map_control_0ed305:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
