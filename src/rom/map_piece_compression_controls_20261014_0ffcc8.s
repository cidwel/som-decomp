.setcpu "65816"
.segment "CODE"
.org $FCC8
map_control_0ffcc8:
    .byte $D2 ; same-value copy count/distance
