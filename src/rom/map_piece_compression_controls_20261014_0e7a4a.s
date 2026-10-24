.setcpu "65816"
.segment "CODE"
.org $7A4A
map_control_0e7a4a:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
