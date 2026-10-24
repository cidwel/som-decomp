.setcpu "65816"
.segment "CODE"
.org $963F
map_control_0d963f:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
