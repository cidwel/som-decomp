.setcpu "65816"
.segment "CODE"
.org $F6C2
map_control_0cf6c2:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
