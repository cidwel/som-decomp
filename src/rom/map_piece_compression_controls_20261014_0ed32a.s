.setcpu "65816"
.segment "CODE"
.org $D32A
map_control_0ed32a:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
