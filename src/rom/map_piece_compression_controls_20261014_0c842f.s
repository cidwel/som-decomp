.setcpu "65816"
.segment "CODE"
.org $842F
map_control_0c842f:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
