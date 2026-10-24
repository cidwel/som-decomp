.setcpu "65816"
.segment "CODE"
.org $7201
map_control_0c7201:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
