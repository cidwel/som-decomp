.setcpu "65816"
.segment "CODE"
.org $CC70
map_control_0ecc70:
    .byte $C1 ; same-value copy count/distance
