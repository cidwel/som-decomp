.setcpu "65816"
.segment "CODE"
.org $B35A
map_control_0db35a:
    .byte $C1 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
