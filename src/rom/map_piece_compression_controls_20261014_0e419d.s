.setcpu "65816"
.segment "CODE"
.org $419D
map_control_0e419d:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
