.setcpu "65816"
.segment "CODE"
.org $C6D8
map_control_0fc6d8:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
