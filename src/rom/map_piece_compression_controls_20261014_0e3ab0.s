.setcpu "65816"
.segment "CODE"
.org $3AB0
map_control_0e3ab0:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
