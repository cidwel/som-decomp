.setcpu "65816"
.segment "CODE"
.org $BBB0
map_control_0ebbb0:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
