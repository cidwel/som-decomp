.setcpu "65816"
.segment "CODE"
.org $F486
map_control_0df486:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
