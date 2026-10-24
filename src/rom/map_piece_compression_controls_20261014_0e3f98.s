.setcpu "65816"
.segment "CODE"
.org $3F98
map_control_0e3f98:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
