.setcpu "65816"
.segment "CODE"
.org $A934
map_control_0ea934:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
