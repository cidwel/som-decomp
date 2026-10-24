.setcpu "65816"
.segment "CODE"
.org $0F82
map_control_0e0f82:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
