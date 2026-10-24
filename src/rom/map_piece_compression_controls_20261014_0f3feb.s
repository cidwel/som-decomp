.setcpu "65816"
.segment "CODE"
.org $3FEB
map_control_0f3feb:
    .byte $C1 ; same-value copy count/distance
