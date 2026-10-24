.setcpu "65816"
.segment "CODE"
.org $24C6
map_control_0d24c6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
