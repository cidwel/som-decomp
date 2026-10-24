.setcpu "65816"
.segment "CODE"
.org $E489
map_control_0ee489:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
