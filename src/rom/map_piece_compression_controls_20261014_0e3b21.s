.setcpu "65816"
.segment "CODE"
.org $3B21
map_control_0e3b21:
    .byte $E8 ; backreference distance high bits
    .byte $58 ; distance low bit/count
