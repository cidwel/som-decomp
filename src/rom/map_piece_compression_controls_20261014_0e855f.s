.setcpu "65816"
.segment "CODE"
.org $855F
map_control_0e855f:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
