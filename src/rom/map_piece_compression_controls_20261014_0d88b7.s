.setcpu "65816"
.segment "CODE"
.org $88B7
map_control_0d88b7:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
