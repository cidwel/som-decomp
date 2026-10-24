.setcpu "65816"
.segment "CODE"
.org $1F44
map_control_0d1f44:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
