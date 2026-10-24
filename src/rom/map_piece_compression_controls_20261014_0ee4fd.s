.setcpu "65816"
.segment "CODE"
.org $E4FD
map_control_0ee4fd:
    .byte $E9 ; backreference distance high bits
    .byte $9A ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
