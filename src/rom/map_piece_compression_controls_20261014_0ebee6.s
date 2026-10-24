.setcpu "65816"
.segment "CODE"
.org $BEE6
map_control_0ebee6:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
