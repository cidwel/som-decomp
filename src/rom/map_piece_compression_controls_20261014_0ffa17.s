.setcpu "65816"
.segment "CODE"
.org $FA17
map_control_0ffa17:
    .byte $C2 ; same-value copy count/distance
