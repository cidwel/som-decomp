.setcpu "65816"
.segment "CODE"
.org $C876
map_control_0ec876:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
