.setcpu "65816"
.segment "CODE"
.org $31C2
map_control_0c31c2:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
