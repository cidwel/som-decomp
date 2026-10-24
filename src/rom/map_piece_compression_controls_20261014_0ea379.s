.setcpu "65816"
.segment "CODE"
.org $A379
map_control_0ea379:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
