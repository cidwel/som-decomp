.setcpu "65816"
.segment "CODE"
.org $AD3E
map_control_0fad3e:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
