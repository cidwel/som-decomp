.setcpu "65816"
.segment "CODE"
.org $8A18
map_control_0d8a18:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
