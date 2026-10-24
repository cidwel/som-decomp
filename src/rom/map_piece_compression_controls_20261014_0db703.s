.setcpu "65816"
.segment "CODE"
.org $B703
map_control_0db703:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
