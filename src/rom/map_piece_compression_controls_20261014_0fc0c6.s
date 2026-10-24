.setcpu "65816"
.segment "CODE"
.org $C0C6
map_control_0fc0c6:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
