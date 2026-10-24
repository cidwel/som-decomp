.setcpu "65816"
.segment "CODE"
.org $842C
map_control_0c842c:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
