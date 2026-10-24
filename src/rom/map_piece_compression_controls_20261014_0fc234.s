.setcpu "65816"
.segment "CODE"
.org $C234
map_control_0fc234:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
