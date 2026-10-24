.setcpu "65816"
.segment "CODE"
.org $F261
map_control_0ef261:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
