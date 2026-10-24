.setcpu "65816"
.segment "CODE"
.org $858E
map_control_0c858e:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
