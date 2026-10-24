.setcpu "65816"
.segment "CODE"
.org $E6DC
map_control_0ee6dc:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
