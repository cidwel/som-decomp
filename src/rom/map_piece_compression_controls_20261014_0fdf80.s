.setcpu "65816"
.segment "CODE"
.org $DF80
map_control_0fdf80:
    .byte $C2 ; same-value copy count/distance
