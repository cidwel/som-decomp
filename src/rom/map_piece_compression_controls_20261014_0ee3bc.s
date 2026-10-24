.setcpu "65816"
.segment "CODE"
.org $E3BC
map_control_0ee3bc:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
