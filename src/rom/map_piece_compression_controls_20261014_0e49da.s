.setcpu "65816"
.segment "CODE"
.org $49DA
map_control_0e49da:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
