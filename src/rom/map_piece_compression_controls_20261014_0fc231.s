.setcpu "65816"
.segment "CODE"
.org $C231
map_control_0fc231:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
