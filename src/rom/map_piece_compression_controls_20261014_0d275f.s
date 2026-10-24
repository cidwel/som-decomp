.setcpu "65816"
.segment "CODE"
.org $275F
map_control_0d275f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
