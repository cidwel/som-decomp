.setcpu "65816"
.segment "CODE"
.org $E217
map_control_0ee217:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
