.setcpu "65816"
.segment "CODE"
.org $C116
map_control_0fc116:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
