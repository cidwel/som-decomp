.setcpu "65816"
.segment "CODE"
.org $4B5F
map_control_0c4b5f:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
