.setcpu "65816"
.segment "CODE"
.org $7F62
map_control_0d7f62:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
