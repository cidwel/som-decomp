.setcpu "65816"
.segment "CODE"
.org $BB7F
map_control_0ebb7f:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
