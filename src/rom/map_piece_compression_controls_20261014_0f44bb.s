.setcpu "65816"
.segment "CODE"
.org $44BB
map_control_0f44bb:
    .byte $C1 ; same-value copy count/distance
