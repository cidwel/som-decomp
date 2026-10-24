.setcpu "65816"
.segment "CODE"
.org $E42A
map_control_0ee42a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
