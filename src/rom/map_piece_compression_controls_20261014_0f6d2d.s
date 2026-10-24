.setcpu "65816"
.segment "CODE"
.org $6D2D
map_control_0f6d2d:
    .byte $DF ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
