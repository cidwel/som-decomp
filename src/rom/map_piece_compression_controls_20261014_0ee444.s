.setcpu "65816"
.segment "CODE"
.org $E444
map_control_0ee444:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
