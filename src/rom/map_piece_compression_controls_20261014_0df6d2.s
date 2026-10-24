.setcpu "65816"
.segment "CODE"
.org $F6D2
map_control_0df6d2:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
