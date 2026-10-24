.setcpu "65816"
.segment "CODE"
.org $F623
map_control_0ef623:
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
