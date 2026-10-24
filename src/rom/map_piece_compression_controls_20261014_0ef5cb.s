.setcpu "65816"
.segment "CODE"
.org $F5CB
map_control_0ef5cb:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $60 ; distance low bit/count
