.setcpu "65816"
.segment "CODE"
.org $FC0F
map_control_0dfc0f:
    .byte $C2 ; same-value copy count/distance
