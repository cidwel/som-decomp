.setcpu "65816"
.segment "CODE"
.org $4870
map_control_0f4870:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
