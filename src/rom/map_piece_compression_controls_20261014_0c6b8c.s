.setcpu "65816"
.segment "CODE"
.org $6B8C
map_control_0c6b8c:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
