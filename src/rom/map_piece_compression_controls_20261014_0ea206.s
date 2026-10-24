.setcpu "65816"
.segment "CODE"
.org $A206
map_control_0ea206:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
