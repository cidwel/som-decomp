.setcpu "65816"
.segment "CODE"
.org $180F
map_control_0f180f:
    .byte $C1 ; same-value copy count/distance
