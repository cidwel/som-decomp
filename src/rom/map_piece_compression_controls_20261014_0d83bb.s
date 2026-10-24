.setcpu "65816"
.segment "CODE"
.org $83BB
map_control_0d83bb:
    .byte $C1 ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
