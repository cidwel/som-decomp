.setcpu "65816"
.segment "CODE"
.org $F1E1
map_control_0ff1e1:
    .byte $E8 ; backreference distance high bits
    .byte $35 ; distance low bit/count
