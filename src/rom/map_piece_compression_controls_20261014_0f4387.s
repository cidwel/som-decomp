.setcpu "65816"
.segment "CODE"
.org $4387
map_control_0f4387:
    .byte $F1 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
