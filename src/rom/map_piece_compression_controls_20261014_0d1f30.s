.setcpu "65816"
.segment "CODE"
.org $1F30
map_control_0d1f30:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
