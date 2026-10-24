.setcpu "65816"
.segment "CODE"
.org $2F93
map_control_0f2f93:
    .byte $DF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
