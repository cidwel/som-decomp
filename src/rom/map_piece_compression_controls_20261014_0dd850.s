.setcpu "65816"
.segment "CODE"
.org $D850
map_control_0dd850:
    .byte $C1 ; same-value copy count/distance
