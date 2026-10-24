.setcpu "65816"
.segment "CODE"
.org $358F
map_control_0d358f:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
