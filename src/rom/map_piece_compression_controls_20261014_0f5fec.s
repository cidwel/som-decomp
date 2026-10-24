.setcpu "65816"
.segment "CODE"
.org $5FEC
map_control_0f5fec:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
