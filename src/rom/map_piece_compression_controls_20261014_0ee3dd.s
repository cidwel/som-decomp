.setcpu "65816"
.segment "CODE"
.org $E3DD
map_control_0ee3dd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
