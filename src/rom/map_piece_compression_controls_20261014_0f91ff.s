.setcpu "65816"
.segment "CODE"
.org $91FF
map_control_0f91ff:
    .byte $C1 ; same-value copy count/distance
