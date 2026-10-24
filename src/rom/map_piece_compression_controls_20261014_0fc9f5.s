.setcpu "65816"
.segment "CODE"
.org $C9F5
map_control_0fc9f5:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
