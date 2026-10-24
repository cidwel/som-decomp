.setcpu "65816"
.segment "CODE"
.org $DAC5
map_control_0fdac5:
    .byte $C3 ; same-value copy count/distance
