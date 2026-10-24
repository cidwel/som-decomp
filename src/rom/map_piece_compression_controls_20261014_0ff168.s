.setcpu "65816"
.segment "CODE"
.org $F168
map_control_0ff168:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
