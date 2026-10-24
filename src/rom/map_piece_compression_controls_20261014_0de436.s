.setcpu "65816"
.segment "CODE"
.org $E436
map_control_0de436:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
