.setcpu "65816"
.segment "CODE"
.org $BF7A
map_control_0ebf7a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
