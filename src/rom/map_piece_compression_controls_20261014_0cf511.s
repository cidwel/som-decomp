.setcpu "65816"
.segment "CODE"
.org $F511
map_control_0cf511:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
