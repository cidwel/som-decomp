.setcpu "65816"
.segment "CODE"
.org $C1AF
map_control_0fc1af:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
