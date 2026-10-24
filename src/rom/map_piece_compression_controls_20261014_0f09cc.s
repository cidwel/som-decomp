.setcpu "65816"
.segment "CODE"
.org $09CC
map_control_0f09cc:
    .byte $C2 ; same-value copy count/distance
