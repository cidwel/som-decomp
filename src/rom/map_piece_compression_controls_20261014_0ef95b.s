.setcpu "65816"
.segment "CODE"
.org $F95B
map_control_0ef95b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
