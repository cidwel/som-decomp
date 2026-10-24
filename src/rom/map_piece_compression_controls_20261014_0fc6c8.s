.setcpu "65816"
.segment "CODE"
.org $C6C8
map_control_0fc6c8:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
