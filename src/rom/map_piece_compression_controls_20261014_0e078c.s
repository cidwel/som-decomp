.setcpu "65816"
.segment "CODE"
.org $078C
map_control_0e078c:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
