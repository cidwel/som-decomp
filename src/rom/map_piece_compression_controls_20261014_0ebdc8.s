.setcpu "65816"
.segment "CODE"
.org $BDC8
map_control_0ebdc8:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
