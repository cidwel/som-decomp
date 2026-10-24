.setcpu "65816"
.segment "CODE"
.org $8CD4
map_control_0d8cd4:
    .byte $C1 ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
