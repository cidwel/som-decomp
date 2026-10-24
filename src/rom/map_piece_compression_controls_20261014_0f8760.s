.setcpu "65816"
.segment "CODE"
.org $8760
map_control_0f8760:
    .byte $C3 ; same-value copy count/distance
