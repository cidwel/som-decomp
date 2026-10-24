.setcpu "65816"
.segment "CODE"
.org $E47D
map_control_0ee47d:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
