.setcpu "65816"
.segment "CODE"
.org $7D30
map_control_0c7d30:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
