.setcpu "65816"
.segment "CODE"
.org $E7DC
map_control_0ee7dc:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
