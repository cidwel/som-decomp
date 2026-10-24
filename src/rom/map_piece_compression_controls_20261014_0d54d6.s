.setcpu "65816"
.segment "CODE"
.org $54D6
map_control_0d54d6:
    .byte $C1 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
