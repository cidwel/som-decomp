.setcpu "65816"
.segment "CODE"
.org $C9D6
map_control_0fc9d6:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
