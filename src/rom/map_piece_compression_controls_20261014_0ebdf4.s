.setcpu "65816"
.segment "CODE"
.org $BDF4
map_control_0ebdf4:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
