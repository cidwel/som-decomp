.setcpu "65816"
.segment "CODE"
.org $DF80
map_control_0edf80:
    .byte $C1 ; same-value copy count/distance
