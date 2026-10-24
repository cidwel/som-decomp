.setcpu "65816"
.segment "CODE"
.org $6D25
map_control_0d6d25:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
