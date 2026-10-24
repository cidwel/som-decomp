.setcpu "65816"
.segment "CODE"
.org $E448
map_control_0ee448:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
