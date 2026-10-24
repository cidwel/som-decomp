.setcpu "65816"
.segment "CODE"
.org $F763
map_control_0cf763:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
