.setcpu "65816"
.segment "CODE"
.org $C9E9
map_control_0fc9e9:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
