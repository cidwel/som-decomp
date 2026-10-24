.setcpu "65816"
.segment "CODE"
.org $EB15
map_control_0deb15:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
