.setcpu "65816"
.segment "CODE"
.org $E1BB
map_control_0ee1bb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
