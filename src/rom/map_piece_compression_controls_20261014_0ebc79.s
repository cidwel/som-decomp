.setcpu "65816"
.segment "CODE"
.org $BC79
map_control_0ebc79:
    .byte $C1 ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
