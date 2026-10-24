.setcpu "65816"
.segment "CODE"
.org $BFB4
map_control_0ebfb4:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
