.setcpu "65816"
.segment "CODE"
.org $3BE8
map_control_0f3be8:
    .byte $C1 ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
