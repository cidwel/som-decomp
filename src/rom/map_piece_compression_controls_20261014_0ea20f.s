.setcpu "65816"
.segment "CODE"
.org $A20F
map_control_0ea20f:
    .byte $C4 ; same-value copy count/distance
