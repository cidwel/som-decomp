.setcpu "65816"
.segment "CODE"
.org $6857
map_control_0c6857:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
