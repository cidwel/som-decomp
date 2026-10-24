.setcpu "65816"
.segment "CODE"
.org $2B85
map_control_0c2b85:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
