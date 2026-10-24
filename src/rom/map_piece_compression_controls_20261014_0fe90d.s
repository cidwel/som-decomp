.setcpu "65816"
.segment "CODE"
.org $E90D
map_control_0fe90d:
    .byte $E9 ; backreference distance high bits
    .byte $88 ; distance low bit/count
