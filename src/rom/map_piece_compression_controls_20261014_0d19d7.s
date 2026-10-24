.setcpu "65816"
.segment "CODE"
.org $19D7
map_control_0d19d7:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
