.setcpu "65816"
.segment "CODE"
.org $D35B
map_control_0ed35b:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
