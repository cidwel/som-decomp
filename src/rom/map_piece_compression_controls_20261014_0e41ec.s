.setcpu "65816"
.segment "CODE"
.org $41EC
map_control_0e41ec:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $91 ; distance low bit/count
