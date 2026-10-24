.setcpu "65816"
.segment "CODE"
.org $CFBD
map_control_0ecfbd:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
