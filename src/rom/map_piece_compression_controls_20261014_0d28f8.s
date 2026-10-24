.setcpu "65816"
.segment "CODE"
.org $28F8
map_control_0d28f8:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
