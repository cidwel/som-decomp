.setcpu "65816"
.segment "CODE"
.org $81EC
map_control_0f81ec:
    .byte $C2 ; same-value copy count/distance
