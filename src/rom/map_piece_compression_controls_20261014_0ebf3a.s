.setcpu "65816"
.segment "CODE"
.org $BF3A
map_control_0ebf3a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
