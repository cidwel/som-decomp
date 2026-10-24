.setcpu "65816"
.segment "CODE"
.org $491F
map_control_0d491f:
    .byte $E8 ; backreference distance high bits
    .byte $AB ; distance low bit/count
