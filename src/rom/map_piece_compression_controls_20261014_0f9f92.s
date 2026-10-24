.setcpu "65816"
.segment "CODE"
.org $9F92
map_control_0f9f92:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
