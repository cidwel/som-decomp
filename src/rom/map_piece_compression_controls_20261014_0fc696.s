.setcpu "65816"
.segment "CODE"
.org $C696
map_control_0fc696:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
