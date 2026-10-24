.setcpu "65816"
.segment "CODE"
.org $8017
map_control_0f8017:
    .byte $C9 ; same-value copy count/distance
