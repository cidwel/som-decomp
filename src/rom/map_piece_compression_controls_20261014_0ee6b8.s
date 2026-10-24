.setcpu "65816"
.segment "CODE"
.org $E6B8
map_control_0ee6b8:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
