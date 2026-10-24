.setcpu "65816"
.segment "CODE"
.org $BEF0
map_control_0ebef0:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
