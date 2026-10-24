.setcpu "65816"
.segment "CODE"
.org $55F8
map_control_0f55f8:
    .byte $C1 ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
