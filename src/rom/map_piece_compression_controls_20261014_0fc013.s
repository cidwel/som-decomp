.setcpu "65816"
.segment "CODE"
.org $C013
map_control_0fc013:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
