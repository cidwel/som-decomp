.setcpu "65816"
.segment "CODE"
.org $BFC7
map_control_0ebfc7:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
