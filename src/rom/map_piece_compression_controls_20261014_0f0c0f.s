.setcpu "65816"
.segment "CODE"
.org $0C0F
map_control_0f0c0f:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
