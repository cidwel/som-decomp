.setcpu "65816"
.segment "CODE"
.org $8023
map_control_0d8023:
    .byte $C2 ; same-value copy count/distance
