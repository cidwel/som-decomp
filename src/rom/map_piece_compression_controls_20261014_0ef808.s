.setcpu "65816"
.segment "CODE"
.org $F808
map_control_0ef808:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
