.setcpu "65816"
.segment "CODE"
.org $4C9C
map_control_0d4c9c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
