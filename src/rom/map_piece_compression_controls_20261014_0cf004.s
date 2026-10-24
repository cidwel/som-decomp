.setcpu "65816"
.segment "CODE"
.org $F004
map_control_0cf004:
    .byte $C2 ; same-value copy count/distance
