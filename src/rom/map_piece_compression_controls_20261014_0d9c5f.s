.setcpu "65816"
.segment "CODE"
.org $9C5F
map_control_0d9c5f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
