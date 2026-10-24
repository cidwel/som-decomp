.setcpu "65816"
.segment "CODE"
.org $6512
map_control_0f6512:
    .byte $C3 ; same-value copy count/distance
