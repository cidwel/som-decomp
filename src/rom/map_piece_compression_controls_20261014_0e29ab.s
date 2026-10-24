.setcpu "65816"
.segment "CODE"
.org $29AB
map_control_0e29ab:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
