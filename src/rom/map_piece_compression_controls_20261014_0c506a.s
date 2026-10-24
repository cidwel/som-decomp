.setcpu "65816"
.segment "CODE"
.org $506A
map_control_0c506a:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
