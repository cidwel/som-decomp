.setcpu "65816"
.segment "CODE"
.org $BFF5
map_control_0ebff5:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
