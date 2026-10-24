.setcpu "65816"
.segment "CODE"
.org $4841
map_control_0f4841:
    .byte $F2 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
