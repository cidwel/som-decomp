.setcpu "65816"
.segment "CODE"
.org $19D4
map_control_0e19d4:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
