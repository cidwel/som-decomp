.setcpu "65816"
.segment "CODE"
.org $CE6D
map_control_0ece6d:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
