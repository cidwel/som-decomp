.setcpu "65816"
.segment "CODE"
.org $0F65
map_control_0c0f65:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
