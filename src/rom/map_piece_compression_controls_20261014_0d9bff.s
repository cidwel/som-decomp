.setcpu "65816"
.segment "CODE"
.org $9BFF
map_control_0d9bff:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
