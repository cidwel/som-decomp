.setcpu "65816"
.segment "CODE"
.org $984C
map_control_0f984c:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
