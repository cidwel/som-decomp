.setcpu "65816"
.segment "CODE"
.org $2B29
map_control_0f2b29:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
