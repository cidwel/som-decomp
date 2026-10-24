.setcpu "65816"
.segment "CODE"
.org $9508
map_control_0e9508:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
