.setcpu "65816"
.segment "CODE"
.org $3A35
map_control_0c3a35:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
