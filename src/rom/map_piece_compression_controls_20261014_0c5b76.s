.setcpu "65816"
.segment "CODE"
.org $5B76
map_control_0c5b76:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
