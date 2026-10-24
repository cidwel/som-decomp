.setcpu "65816"
.segment "CODE"
.org $BB4F
map_control_0ebb4f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
