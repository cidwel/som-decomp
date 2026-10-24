.setcpu "65816"
.segment "CODE"
.org $D318
map_control_0ed318:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
