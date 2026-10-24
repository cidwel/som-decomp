.setcpu "65816"
.segment "CODE"
.org $8D4F
map_control_0f8d4f:
    .byte $C1 ; same-value copy count/distance
    .byte $DE ; same-value copy count/distance
