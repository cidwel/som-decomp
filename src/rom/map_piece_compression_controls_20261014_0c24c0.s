.setcpu "65816"
.segment "CODE"
.org $24C0
map_control_0c24c0:
    .byte $E8 ; backreference distance high bits
    .byte $7D ; distance low bit/count
