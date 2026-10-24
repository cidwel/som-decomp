.setcpu "65816"
.segment "CODE"
.org $0F74
map_control_0c0f74:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
