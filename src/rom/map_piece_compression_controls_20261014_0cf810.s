.setcpu "65816"
.segment "CODE"
.org $F810
map_control_0cf810:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
