.setcpu "65816"
.segment "CODE"
.org $CE26
map_control_0fce26:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
