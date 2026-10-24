.setcpu "65816"
.segment "CODE"
.org $28D8
map_control_0d28d8:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
