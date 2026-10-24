.setcpu "65816"
.segment "CODE"
.org $C93E
map_control_0fc93e:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
