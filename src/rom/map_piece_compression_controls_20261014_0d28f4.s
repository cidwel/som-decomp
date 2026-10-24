.setcpu "65816"
.segment "CODE"
.org $28F4
map_control_0d28f4:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
