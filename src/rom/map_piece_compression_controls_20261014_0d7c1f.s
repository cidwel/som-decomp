.setcpu "65816"
.segment "CODE"
.org $7C1F
map_control_0d7c1f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
