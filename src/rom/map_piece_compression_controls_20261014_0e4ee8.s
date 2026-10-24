.setcpu "65816"
.segment "CODE"
.org $4EE8
map_control_0e4ee8:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
