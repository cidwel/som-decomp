.setcpu "65816"
.segment "CODE"
.org $C6A9
map_control_0fc6a9:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
