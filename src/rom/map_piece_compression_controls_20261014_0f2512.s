.setcpu "65816"
.segment "CODE"
.org $2512
map_control_0f2512:
    .byte $C2 ; same-value copy count/distance
