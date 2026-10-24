.setcpu "65816"
.segment "CODE"
.org $6C82
map_control_0d6c82:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
