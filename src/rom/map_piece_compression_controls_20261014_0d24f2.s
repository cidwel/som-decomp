.setcpu "65816"
.segment "CODE"
.org $24F2
map_control_0d24f2:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
