.setcpu "65816"
.segment "CODE"
.org $BF4B
map_control_0ebf4b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
