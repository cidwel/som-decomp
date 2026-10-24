.setcpu "65816"
.segment "CODE"
.org $F97E
map_control_0cf97e:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
