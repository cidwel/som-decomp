.setcpu "65816"
.segment "CODE"
.org $BDAC
map_control_0ebdac:
    .byte $EF ; backreference distance high bits
    .byte $90 ; distance low bit/count
