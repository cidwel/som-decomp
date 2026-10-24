.setcpu "65816"
.segment "CODE"
.org $F93B
map_control_0ef93b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
