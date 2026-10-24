.setcpu "65816"
.segment "CODE"
.org $C6B3
map_control_0fc6b3:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
