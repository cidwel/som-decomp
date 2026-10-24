.setcpu "65816"
.segment "CODE"
.org $D55A
map_control_0dd55a:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
