.setcpu "65816"
.segment "CODE"
.org $4B8E
map_control_0c4b8e:
    .byte $C1 ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $F1 ; progressive-copy count
