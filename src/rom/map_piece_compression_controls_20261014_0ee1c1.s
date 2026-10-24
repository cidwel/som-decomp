.setcpu "65816"
.segment "CODE"
.org $E1C1
map_control_0ee1c1:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
