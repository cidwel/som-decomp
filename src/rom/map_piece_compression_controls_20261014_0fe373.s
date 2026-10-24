.setcpu "65816"
.segment "CODE"
.org $E373
map_control_0fe373:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
