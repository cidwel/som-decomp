.setcpu "65816"
.segment "CODE"
.org $5255
map_control_0d5255:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
