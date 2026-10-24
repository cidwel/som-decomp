.setcpu "65816"
.segment "CODE"
.org $7A6B
map_control_0c7a6b:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
