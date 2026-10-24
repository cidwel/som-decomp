.setcpu "65816"
.segment "CODE"
.org $F1B7
map_control_0ff1b7:
    .byte $E8 ; backreference distance high bits
    .byte $35 ; distance low bit/count
