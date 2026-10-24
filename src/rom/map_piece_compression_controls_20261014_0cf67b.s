.setcpu "65816"
.segment "CODE"
.org $F67B
map_control_0cf67b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
