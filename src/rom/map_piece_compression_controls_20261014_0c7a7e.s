.setcpu "65816"
.segment "CODE"
.org $7A7E
map_control_0c7a7e:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
