.setcpu "65816"
.segment "CODE"
.org $61BC
map_control_0e61bc:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
