.setcpu "65816"
.segment "CODE"
.org $F78D
map_control_0ff78d:
    .byte $D1 ; same-value copy count/distance
