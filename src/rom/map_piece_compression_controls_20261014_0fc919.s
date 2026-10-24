.setcpu "65816"
.segment "CODE"
.org $C919
map_control_0fc919:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
