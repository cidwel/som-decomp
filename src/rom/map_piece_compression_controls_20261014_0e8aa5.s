.setcpu "65816"
.segment "CODE"
.org $8AA5
map_control_0e8aa5:
    .byte $EB ; backreference distance high bits
    .byte $8F ; distance low bit/count
