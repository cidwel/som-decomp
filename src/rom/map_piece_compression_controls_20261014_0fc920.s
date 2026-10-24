.setcpu "65816"
.segment "CODE"
.org $C920
map_control_0fc920:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
