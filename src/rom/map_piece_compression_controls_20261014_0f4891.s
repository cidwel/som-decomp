.setcpu "65816"
.segment "CODE"
.org $4891
map_control_0f4891:
    .byte $F2 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
