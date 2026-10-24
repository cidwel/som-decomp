.setcpu "65816"
.segment "CODE"
.org $C0FD
map_control_0fc0fd:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
