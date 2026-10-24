.setcpu "65816"
.segment "CODE"
.org $B9A4
map_control_0db9a4:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
