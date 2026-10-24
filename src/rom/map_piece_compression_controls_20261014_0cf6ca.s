.setcpu "65816"
.segment "CODE"
.org $F6CA
map_control_0cf6ca:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
