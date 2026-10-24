.setcpu "65816"
.segment "CODE"
.org $C358
map_control_0ec358:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
